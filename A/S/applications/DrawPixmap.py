
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QFont, QPixmap, QColor, QBrush

def drawRect(painter, rect, args):
    '''
    painter                 #QPainter
    args:{
        text:str            一段字符串
        text_flag:int       参数

        pic:""              背景图片的文件路径
        color:QColor        填充背景颜色
    }
    '''
    if painter and rect:
        if args.get("pic"):
            painter.drawPixmap(rect, QPixmap(args["pic"]))
        elif args.get("color") and isinstance(args.get("color"), QColor):
            painter.setBrush(QBrush(args.get("color")))
            painter.drawRect(rect)

        if args.get("text"):
            painter.drawText(rect, args.get("text_flag", Qt.AlignHCenter | Qt.AlignVCenter), args["text"])


