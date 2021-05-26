'''
    MineSweeper:扫雷小游戏
'''
import random, os

from PyQt5.QtCore import QPoint, QRect, Qt
from PyQt5.QtGui import QColor, QPainter, QPixmap, QFont

from .AbstractApp import AbstractApp
from .DrawPixmap import drawRect

class mine():
    def __init__(self) -> None:
        self.rect = None
        self.args = dict()
        self.isMine = False     #f是否是地雷
        self.isCheck = False    #z是否检查
        self.isMark = False     #是否标记为地雷
        self.num = 0            #t周围地雷个数
        pass
    pass

class MineSweeper(AbstractApp):
    '''
    浅绿	170	215	80
    深绿	160	210	70
    浅棕	230	195	160
    深棕	215	185	155
    '''
    LightGreen  = QColor(180, 220, 100)
    DarkGreen   = QColor(155, 205, 65)
    LightBrown  = QColor(230, 195, 160)
    DarkBrown   = QColor(215, 185, 155)
    
    def __init__(self) -> None:
        self.num_x = 10
        self.num_y = 10
        self.totalNum = self.num_x * self.num_y
        self.mineNum = self.totalNum // 8
        self.mines = []
        self.width = 100
        self.height = 100

        #状态   0   正在游戏    1   胜利    -1  失败
        self.status = 0
        self.firstPress = True

        self.currentWindowWidth = None
        self.currentWindowHeight = None

        self.createItems()
        pass

    def createItems(self, x = 10, y = 10):
        self.mines.clear()

        self.status = 0
        self.num_x = x
        self.num_y = y
        self.totalNum = x * y
        self.mineNum = self.totalNum // 8
        for i in range(self.totalNum):
            _item = mine()
            _item.rect = QRect((i % self.num_x)*self.height, (i // self.num_x)*self.width, self.width, self.height)
            if (i // self.num_x + i % self.num_x) % 2 == 0:
                _item.args["color"] = MineSweeper.LightGreen
            else:
                _item.args["color"] = MineSweeper.DarkGreen
            self.mines.append(_item)
        #self.createMines()
        pass

    def createMines(self, index):
        i = 0
        while i < self.mineNum:
            n = random.randint(0, self.totalNum-1)
            if n != index and not self.mines[n].isMine:
                self.mines[n].isMine = True
                self.mines[n].num = -1
                i += 1

        for i in range(self.totalNum):
            if not self.mines[i].isMine:
                if i + 1 > self.num_x and self.mines[i-self.num_x].isMine:
                    self.mines[i].num += 1
                if i > self.num_x and i % self.num_x and self.mines[i-1-self.num_x].isMine:
                    self.mines[i].num += 1
                if i + 1 > self.num_x and (i + 1) % self.num_x and self.mines[i+1-self.num_x].isMine:
                    self.mines[i].num += 1
                if i % self.num_x and self.mines[i - 1].isMine:
                    self.mines[i].num += 1
                if (i + 1) % self.num_x and self.mines[i + 1].isMine:
                    self.mines[i].num += 1
                if i + self.num_x < self.totalNum and self.mines[i + self.num_x].isMine:
                    self.mines[i].num += 1
                if i % self.num_x and i + self.num_x - 1 < self.totalNum and self.mines[i + self.num_x -1].isMine:
                    self.mines[i].num += 1
                if (i + 1) % self.num_x and i + self.num_x + 1 < self.totalNum and self.mines[i + self.num_x + 1].isMine:
                    self.mines[i].num += 1
            pass
    
    def openMine(self, index):
        self.mines[index].isCheck = True
        if index + 1 > self.num_x:
            i = index - self.num_x  
            self.checkMine(i)
        if index > self.num_x and index % self.num_x:
            i = index - self.num_x - 1
            self.checkMine(i)
        if index + 1 > self.num_x and (index + 1) % self.num_x:
            i = index - self.num_x + 1
            self.checkMine(i)
        if index % self.num_x:
            i = index - 1
            self.checkMine(i)
        if (index + 1) % self.num_x:
            i = index + 1
            self.checkMine(i)
        if index + self.num_x < self.totalNum:
            i = index + self.num_x
            self.checkMine(i)
        if index % self.num_x and index + self.num_x - 1 < self.totalNum:
            i = index + self.num_x - 1
            self.checkMine(i)
        if (index + 1) % self.num_x and (index + self.num_x + 1) < self.totalNum:
            i = index + self.num_x + 1
            self.checkMine(i)
        pass

    def checkMine(self, i):
        if (i // self.num_x + i % self.num_x) % 2 == 0:
            self.mines[i].args["color"] = MineSweeper.LightBrown
        else:
            self.mines[i].args["color"] = MineSweeper.DarkBrown

        if self.mines[i].num > 0:
            self.mines[i].args["text"] = str(self.mines[i].num)
        elif self.mines[i].num == 0 and not self.mines[i].isCheck:
            self.openMine(i)
        pass

    def markMine(self, index):
        self.mines[index].isMark = not self.mines[index].isMark
        if self.mines[index].isMark:    
            self.mines[index].args["color"] = QColor(255, 0, 0)
        else:
            if (index // self.num_x + index % self.num_x) % 2 == 0:
                self.mines[index].args["color"] = MineSweeper.LightGreen
            else:
                self.mines[index].args["color"] = MineSweeper.DarkGreen

        if self.isWin():
            self.status = 1

    def isWin(self):
        markNum = 0
        for m in self.mines:
            if m.isMine and m.isMark:
                markNum += 1

        if markNum == self.mineNum:
            return True

        return False

    def GetPixmap(self):
        if not self.currentWindowHeight or not self.currentWindowWidth:
            return None

        _w = self.num_x * self.width
        _h = self.num_y * self.height

        _pixmap = QPixmap(_w, _h)
        _painter = QPainter()
        _painter.begin(_pixmap)
        font = QFont("宋体", self.width // 2)
        _painter.setFont(font)

        if self.status == 0:
            for i in range(self.totalNum):
                drawRect(_painter, self.mines[i].rect, self.mines[i].args)
        elif self.status == 1:
            picPath = os.getcwd() + '\\cat.jpg'
            pic = QPixmap(picPath)
            _painter.drawPixmap(0, 0, _w, _h, pic)
            pass
        elif self.status == -1:
            for i in range(self.totalNum):
                if self.mines[i].isMine:
                    self.mines[i].args["color"] = QColor(255, 0, 0)
                else:
                    if (i // self.num_x + i % self.num_x) % 2 == 0:
                        self.mines[i].args["color"] = MineSweeper.LightBrown
                    else:
                        self.mines[i].args["color"] = MineSweeper.DarkBrown

                    if self.mines[i].num > 0:
                        self.mines[i].args["text"] = str(self.mines[i].num)

                drawRect(_painter, self.mines[i].rect, self.mines[i].args)
            pass

        _painter.end()
        _pixmap.save("D:\\1.jpg")

        _rw = _w / self.currentWindowWidth
        _rh = _h / self.currentWindowHeight

        if _rw > _rh:
            _w = self.currentWindowWidth
            _h = int(_h / _rw)
        else:
            _w = int(_w / _rh)
            _h = self.currentWindowHeight

        pixmap = QPixmap(self.currentWindowWidth, self.currentWindowHeight)
        painter = QPainter()
        painter.begin(pixmap)
        painter.drawPixmap((self.currentWindowWidth-_w)//2, (self.currentWindowHeight-_h)//2, \
            _w, _h, _pixmap)
        painter.end()
        pixmap.save("D:\\2.jpg")
        return pixmap

    def DealAllMsg(self, msgs):
        for msg in msgs:
            self.DealMsg(msg)
        pass

    def DealMsg(self, msg):
        if msg[0] == '$size':
            self.currentWindowWidth = int(msg[1])
            self.currentWindowHeight = int(msg[2])
            pass
        elif msg[0] == '$resize':
            pass
        elif msg[0] == '$mouseMove':
            pass
        elif msg[0] == '$mousePress':
            if self.status != 0:
                return

            posx = int(msg[1])
            posy = int(msg[2])
            point = self.GetPoint(posx, posy)
            for i in range(self.totalNum):
                if self.mines[i].rect.contains(point):
                    if msg[3] == "L":
                        if self.firstPress:
                            self.firstPress = False
                            self.createMines(i)
                            if (i // self.num_x + i % self.num_x) % 2 == 0:
                                self.mines[i].args["color"] = MineSweeper.LightBrown
                            else:
                                self.mines[i].args["color"] = MineSweeper.DarkBrown

                            if self.mines[i].num == 0:
                                self.openMine(i)
                            else:
                                self.mines[i].args["text"] = str(self.mines[i].num)

                        else:
                            if self.mines[i].isMine:
                                self.status = -1
                            else:
                                if (i // self.num_x + i % self.num_x) % 2 == 0:
                                    self.mines[i].args["color"] = MineSweeper.LightBrown
                                else:
                                    self.mines[i].args["color"] = MineSweeper.DarkBrown

                                if self.mines[i].num == 0:
                                    self.openMine(i)
                                else:
                                    self.mines[i].args["text"] = str(self.mines[i].num)
                    elif msg[3] == "R":
                        self.markMine(i)
                    break
            pass
        elif msg[0] == '$mouseRelease':
            pass
        elif msg[0] == '$keyPress':
            if int(msg[1]) == Qt.Key_R or int(msg[1]) == Qt.Key_Enter \
                or int(msg[1]) == Qt.Key_Return or int(msg[1]) == Qt.Key_Space:
                self.status = 0
                self.firstPress = True
                self.createItems()
            elif int(msg[1]) == Qt.Key_Q or int(msg[1]) == Qt.Key_Escape:
                print("退出")
                self.status = 1
            pass
        pass

    def GetPoint(self, posx, posy):
        _w = self.num_x * self.width
        _h = self.num_y * self.height

        _rw = _w / self.currentWindowWidth
        _rh = _h / self.currentWindowHeight

        cx = cy = 0

        if _rw > _rh:
            _w = self.currentWindowWidth
            _h = int(_h / _rw)

            cx = int((posx - (self.currentWindowWidth-_w)//2) * _rw)
            cy = int((posy - (self.currentWindowHeight-_h)//2) * _rw)

        else:
            _w = int(_w / _rh)
            _h = self.currentWindowHeight

            cx = int((posx - (self.currentWindowWidth-_w)//2) * _rh)
            cy = int((posy - (self.currentWindowHeight-_h)//2) * _rh)

        
        point = QPoint(cx, cy)
        return point

    pass