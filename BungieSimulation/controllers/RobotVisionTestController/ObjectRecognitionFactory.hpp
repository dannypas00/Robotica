#ifndef OBJ_REC_FACTORY
#define OBJ_REC_FACTORY

#include <iostream>
#include <vector>

namespace bungie {
  class ObjectRecognitionFactory {
    public:
    	ObjectRecognitionFactory();
    	~ObjectRecognitionFactory();

      void detectQrCode();
      void detectCards();

      void filterColorRed();
      void filterColorBlack();


    private:

  };
}

#endif
