#ifndef ISUBJECT
#define ISUBJECT

// All the webots classes are defined in the "webots" namespace
using namespace webots;

#include <iostream>
#include "IObserver.hpp"

namespace bungie {
  class ISubject {
    public:

      virtual void registObserver(IObserver _observer);
      virtual void removeObserver(IObserver _observer);
      virtual void notifyObservers();


    private:

  };
}

#endif
