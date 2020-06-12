from IObserver import IObserver

"""Object recognition custom IObserver class"""
class ObjectRecognitionObserver(IObserver):

    def __init__(self, _type, _callback):
        self.type = _type
        self.callback = _callback

    def update(self, _data):
        self.callback(_data)
