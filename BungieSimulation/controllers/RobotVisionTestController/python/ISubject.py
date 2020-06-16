from abc import ABCMeta, abstractclassmethod

class ISubject():
    __metaclass__ = ABCMeta

    """Regist a new observer"""
    @abstractclassmethod
    def registerObserver(self, _observer): raise NotImplementedError

    """Remove a known observer"""
    @abstractclassmethod
    def removeObserver(self, _observer): raise NotImplementedError

    """Notify all observers"""
    @abstractclassmethod
    def notifyObservers(self): raise NotImplementedError
