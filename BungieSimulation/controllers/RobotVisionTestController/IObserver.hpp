#ifndef IOBSERVER
#define IOBSERVER

// All the webots classes are defined in the "webots" namespace
using namespace webots;

#include <iostream>

namespace bungie {
  class IObserver {
    public:
      virtual void update(int _object);

    private:

  };
}

#endif
