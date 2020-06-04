from abc import ABCMeta, abstractclassmethod

class ISubject():
    __metaclass__ = ABCMeta

    @abstractclassmethod
    def registerObserver(self, _observer): raise NotImplementedError

    @abstractclassmethod
    def removeObserver(self, _observer): raise NotImplementedError

    @abstractclassmethod
    def notifyObservers(self): raise NotImplementedError
