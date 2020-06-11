#ifndef IOBSERVER
#define IOBSERVER

// All the webots classes are defined in the "webots" namespace


#include <iostream>
#include <string.h>

namespace bungie {
  

  class TCPServerObserver{

    public:
      TCPServerObserver(){};
      virtual void update(std::string _key, std::string _value){
        std::cout << _key << " : " << _value << std::endl;
      };

  };
}

#endif
