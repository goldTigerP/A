import sys
from PyQt5.QtWidgets import QApplication

from Form.Form_Login import LoginForm

if __name__ == '__main__':    
    app = QApplication(sys.argv)
    loginWindow = LoginForm()

    loginWindow.show()
    
    print("客户端启动。")
    sys.exit(app.exec_())