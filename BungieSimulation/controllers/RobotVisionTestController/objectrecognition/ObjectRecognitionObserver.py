from IObserver import IObserver

class ObjectRecognitionObserver(IObserver):

    def __init__(self, _type, _callback):
        self.type = _type
        self.callback = _callback

    def update(self, _data):
        self.callback(_data)
