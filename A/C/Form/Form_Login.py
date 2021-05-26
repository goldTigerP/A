# 登录窗口类
# 获取本机和服务器的网络ip、port

import socket, os

from PyQt5.QtWidgets import QWidget

from Form.Ui_login import Ui_Form
from Form.Form_Display import TheMainWindow

class LoginForm(QWidget):
    def __init__(self, parent = None):
        super(LoginForm, self).__init__(parent)
        ui = Ui_Form()
        ui.setupUi(self)
        self.ui = ui

        self.setMinimumSize(360, 240)
        self.setMaximumSize(360, 240)

        self.setWindowTitle("登录")

        _hostname = socket.gethostname()
        _ip = socket.gethostbyname(_hostname)
        
        self.ui.lineEdit_CIP.setText(_ip)    
        self.ui.lineEdit_SIP.setText(_ip)

        self.ui.lineEdit_CPort.setText(str(10000))
        self.ui.lineEdit_SPort.setText(str(10086))
        # 当前工作路径 os.getcwd()   

        self.ui.pushButton_OK.pressed.connect(self.OnButtonOk)
        pass

    def OnButtonOk(self):
        tcpSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        _ipC = self.ui.lineEdit_CIP.text()        
        _portC = int(self.ui.lineEdit_CPort.text())

        _ipS = self.ui.lineEdit_SIP.text()
        _portS = int(self.ui.lineEdit_SPort.text())

        _address = (_ipS, _portS)
        tcpSock.connect(_address)

        if tcpSock:            
            self._mainWindow = TheMainWindow()
            #self._mainWindow.showFullScreen()
            self._mainWindow.show()
            self._mainWindow.socket = tcpSock
        
        self.hide()
        pass

    def OnClose(self):
        #保存本机网络Ip、port及服务器网络Ip、port
        pass
