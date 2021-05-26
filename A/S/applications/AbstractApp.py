class AbstractApp():
    def __init__(self) -> None:
        pass
    
    def GetPixmap(self):
        pass

    def DealAllMsg(self, msgs):
        for msg in msgs:
            self.DealMsg(msg)
        pass

    def DealMsg(self, msg):
        if msg[0] == '$resize:':
            pass
        elif msg[0] == '$mouseMove:':
            pass
        elif msg[0] == '$mousePress:':
            pass
        elif msg[0] == '$mouseRelease:':
            pass
        pass
    pass