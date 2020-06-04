from abc import ABCMeta, abstractclassmethod

class IObserver():
    __metaclass__ = ABCMeta

    """Update the observer to note the change!"""
    @abstractclassmethod
    def update(self, _data): raise NotImplementedError
