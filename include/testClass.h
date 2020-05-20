#ifndef __TESTCLASS_H__
#define __TESTCLASS_H__

#include "utils.h"

class testClass {
   public:
      testClass();
      testClass( std::string new_name, int new_foo, int* new_array, int new_num_vals );
      // Copy Constructor
      testClass( const testClass& other );
      // Copy Assignment constructor
      testClass& operator=( const testClass& other );
      // Move Constructor
      testClass( testClass&& other ) noexcept;
      // Move Assignment constructor
      testClass& operator=( testClass&& other ) noexcept;
      int run();
      void print( std::string prefix = "" ) const;
      ~testClass() {}
   private:
      std::string name;
      int foo;
      int num_vals;
      int* array;
};

#endif // end of #ifndef __TESTCLASS_H__
