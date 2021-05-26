# 展示窗口类
import socket, os, time, struct, threading
from PyQt5 import QtGui

from PyQt5.QtCore import QTimer, QByteArray, QBuffer, QIODevice, Qt
from PyQt5.QtWidgets import QWidget, QLabel
from PyQt5.QtGui import QPixmap

class TheMainWindow(QWidget):
    def __init__(self, parent = None):
        super(TheMainWindow, self).__init__(parent)

        self.label = QLabel(self)
        self.label.move(0, 0)
        self.label.setScaledContents(True)
        self.label.setAttribute(Qt.WA_OpaquePaintEvent)
        self.setMouseTracking(True)
        self.label.setMouseTracking(True)
        
        self.picArray = QByteArray()

        self.resize(800, 600)
        self.setWindowTitle("client")

        self.socket = None

        self.timer_get = QTimer()
        self.timer_get.timeout.connect(self.onTimerGet)
        self.timer_get.start(200)

        self.timer_send = QTimer()
        self.timer_send.timeout.connect(self.onTimerSend)
        self.timer_send.start(200)

        self.lastTime = None   
        self.picinfo_size = struct.calcsize('l')

        self.sendBuff = ''
        self.buffLock = threading.RLock()

    def resizeEvent(self, event):
        newSize = event.size()
        self.label.resize(newSize)
        s = '$resize,'
        s += str(newSize.width())
        s += ','
        s += str(newSize.height())       
        s += ';'
        self.buffLock.acquire()
        self.sendBuff += s
        self.buffLock.release()

    def onTimerGet(self):
        start = time.time()
        buf = self.socket.recv(self.picinfo_size)
        if buf:
            picSize = struct.unpack('l', buf)[0]
            self.picArray.clear()
            recvd_size = 0  # 定义已接收数据的大小
            while not recvd_size == picSize:
                if picSize - recvd_size > 1024:
                    data = self.socket.recv(1024)
                    recvd_size += len(data)
                    self.picArray.append(data)
                else:
                    data = self.socket.recv(picSize - recvd_size)
                    recvd_size = picSize
                    self.picArray.append(data)
            if self.picArray.size() > 0:
                _newPixmap = QPixmap()
                _newPixmap.loadFromData(self.picArray)
                self.label.setPixmap(_newPixmap)

        end = time.time()

        if self.lastTime:
            seconds = start - self.lastTime
            fps  = 1/seconds
            #print("fps:", fps)
            #print("接受数据的时间：", end - start)
        
        self.lastTime = start
        pass
    
    def onTimerSend(self):
        self.buffLock.acquire()
        s = '$size,'
        s += str(self.size().width())
        s += ','
        s += str(self.size().height())       
        s += ';'
        self.sendBuff += s
        dataHead = struct.pack('l', len(self.sendBuff))
        self.socket.send(dataHead)
        self.socket.send(self.sendBuff.encode('utf-8'))

        self.sendBuff = ''
        self.buffLock.release()

    def mouseMoveEvent(self, event):
        pos = event.pos()
        s = '$mouseMove,'
        s += str(pos.x())
        s += ','
        s += str(pos.y())
        s += ';'
        self.buffLock.acquire()
        self.sendBuff += s
        self.buffLock.release()

    def mousePressEvent(self, event):
        pos = event.pos()
        s = '$mousePress,'
        s += str(pos.x())
        s += ','
        s += str(pos.y())
        s += ','
        if event.button() == Qt.LeftButton:
            s += 'L'
        elif event.button() == Qt.RightButton:
            s += "R"
        else:
            s += "E"
        s += ';'
        self.buffLock.acquire()
        self.sendBuff += s
        self.buffLock.release()
        pass

    def mouseReleaseEvent(self, event):
        pos = event.pos()
        s = '$mouseRelease,'
        s += str(pos.x())
        s += ','
        s += str(pos.y())
        s += ';'
        self.buffLock.acquire()
        self.sendBuff += s
        self.buffLock.release()
        pass

    def keyPressEvent(self, event) -> None:
        s = '$keyPress,'
        s += str(event.key())
        s += ';'
        self.buffLock.acquire()
        self.sendBuff += s
        self.buffLock.release()
        return super().keyPressEvent(event)

    pass