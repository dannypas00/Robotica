#ifndef ISUBJECT
#define ISUBJECT

// All the webots classes are defined in the "webots" namespace


#include <iostream>
#include <string>
#include "IObserver.hpp"

namespace bungie {
  class TCPServerSubject {
    public:

      virtual void registObserver(TCPServerObserver _observer){};
      virtual void removeObserver(TCPServerObserver _observer){};
      virtual void notifyObservers(std::string _key, std::string _value){};


    private:

  };
}

#endif
