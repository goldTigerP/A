import socket, threading, time, datetime, sys, os, struct

from PyQt5.QtCore import QTimer, QByteArray, QBuffer, QIODevice
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QPixmap

from applications.ExmapleApp import MineSweeper

class serverWidget(QWidget):
    def __init__(self):
        super(serverWidget, self).__init__()
        socket_service()

def socket_service():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        #s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        _hostname = socket.gethostname()
        _ip = socket.gethostbyname(_hostname)
        _port = 10086
        _address = (_ip, _port)
        s.bind(_address)        
        s.listen(20)
    except socket.error as msg:
        print(msg)
        sys.exit(1)
    print('Waiting connection...')
 
    while True:
        conn, addr = s.accept()

        app = MineSweeper()
        t_out = threading.Thread(target=SendToClient, args=(conn, app))
        t_in = threading.Thread(target=GetFromClient, args=(conn, app))

        t_out.start()
        t_in.start()

def SendToClient(conn, app):
    b = True
    while True:
        '''
        if b:
            _picPath = os.getcwd() + '\\dog.jpg'
            b = False
        else:
            _picPath = os.getcwd() + '\\cat.jpg'
            b = True
        _pixmap = QPixmap(_picPath)
        '''
        _pixmap = app.GetPixmap()
        
        if _pixmap:
            sendPic(conn, _pixmap)

        time.sleep(0.2)

def sendPic(conn, pixmap):
    picArray = QByteArray()
    picBuff = QBuffer(picArray)
    picBuff.open(QIODevice.WriteOnly)

    pixmap.save(picBuff, 'jpg')

    picHead = struct.pack('l', picArray.size())
    conn.send(picHead)
    conn.send(picArray)
    pass

def GetFromClient(conn, app):
    dataInfo_size = struct.calcsize('l')
    while True:
        buf = conn.recv(dataInfo_size)
        if buf:
            dataSize = struct.unpack('l', buf)[0]

            recvd_size = 0  # 定义已接收数据的大小
            text = ''
            while not recvd_size == dataSize:
                if dataSize - recvd_size > 1024:
                    data = conn.recv(1024)
                    recvd_size += len(data)
                    text += data.decode('utf-8')
                else:
                    data = conn.recv(dataSize - recvd_size)
                    recvd_size = dataSize
                    text += data.decode('utf-8')

            if len(text) > 0:
                app.DealAllMsg(TransToMsg(text))

        time.sleep(0.2)

def TransToMsg(text):
    msgs = []
    i = 0
    while i < len(text):
        index = text.find("$", i)
        if index == -1:
            break
        elif text.find(";", index) == -1:
            break
        else:
            _text = text[index:text.find(";", index)]
            msg = _text.split(",")
            msgs.append(msg)
            i = text.find(";", index)

    return msgs

if __name__ == '__main__':
    app = QApplication(sys.argv)
    
    window = serverWidget()
    #window.hide()

    sys.exit(window.exec_())