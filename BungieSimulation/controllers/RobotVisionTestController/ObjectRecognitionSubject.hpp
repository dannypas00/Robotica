#ifndef OBJECT_RECOGNITION_SUBJECT
#define OBJECT_RECOGNITION_SUBJECT

// All the webots classes are defined in the "webots" namespace
using namespace webots;

#include <iostream>
#include "ObjectRecognitionObserver.hpp"

namespace bungie {
  class ObjectRecognitionSubject {
    public:

      virtual void registObserver(ObjectRecognitionObserver* _observer);
      virtual void removeObserver(ObjectRecognitionObserver* _observer);
      virtual void notifyObservers(ObjectRecognitionData* _data);


    private:

  };
}

#endif
