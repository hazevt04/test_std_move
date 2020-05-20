// C++ File for testClass

#include "testClass.h"

testClass::testClass() {
   std::cout << "default constructor: ";
   std::cout << std::endl;
   name = "";
   foo = 0;
   num_vals = 0;
   array = nullptr;
}

testClass::testClass( std::string new_name, int new_foo, int* new_array, int new_num_vals ) {
   std::cout << "constructor: ";
   std::cout << " new_name = " << new_name;
   std::cout << " new_foo = " << new_foo;
   std::cout << " new_num_vals = " << new_num_vals; 
   std::cout << " new_array = { "; 
   for( int index = 0; index < new_num_vals; ++index ) {
      std::cout << new_array[index] << " ";
   }
   std::cout << "}";
   
   array = new int [new_num_vals];
   for( int index = 0; index < new_num_vals; ++index ) {
      array[index] = new_array[index];
   } 
   name = new_name;
   foo = new_foo;
   num_vals = new_num_vals;

   print( "--> this: " );
   std::cout << std::endl;
}

// Copy Constructor
testClass::testClass( const testClass& other ) {
   std::cout << "copy constructor: ";
   other.print();

   array = new int[other.num_vals];
   for( int index = 0; index < other.num_vals; ++index ) {
      array[index] = other.array[index];
   } 
   name = other.name;
   foo = other.foo;
   num_vals = other.num_vals;

   print( "--> this: " );
   std::cout << std::endl;
}

// Copy Assignment operator
testClass& testClass::operator=( const testClass& other ) {
   std::cout << "copy assignment constructor: ";
   other.print();
   print();

   if ( this != &other ) {
      name = other.name;
      foo = other.foo;
      array = new int[other.num_vals];
      for( int index = 0; index < other.num_vals; ++index ) {
         array[index] = other.array[index];
      } 
      num_vals = other.num_vals;
   }
   print( "--> this: " );
   std::cout << std::endl;
   return *this;
}

// Move Constructor
testClass::testClass( testClass&& other ) noexcept {
   std::cout << "move constructor: ";
   other.print( "other: " );

   name = std::move(other.name);
   foo = other.foo;
   num_vals = other.num_vals;
   // This is where move shines. 
   // Since other won't need the array memory after this,
   // just take it
   array = other.array;

   other.name = "";
   other.foo = 0;
   other.num_vals = 0;
   other.array = nullptr;
   
   print( "--> this: " );
   std::cout << std::endl;
}

// Move Assignment operator
testClass& testClass::operator=( testClass&& other ) noexcept {
   std::cout << "move assignment constructor: ";
   other.print( "other: " );
   print();

   if ( this != &other ) {
      delete[] array;

      name = std::move(other.name);
      foo = other.foo;
      num_vals = other.num_vals;
      // This is where move shines. 
      // Since other won't need the array memory after this,
      // just take it
      array = other.array;
      
      other.name = "";
      other.foo = 0;
      other.num_vals = 0;
      other.array = nullptr;
   }

   print( "--> this: " );
   std::cout << std::endl;
   return *this;
}

void testClass::print( std::string prefix ) const {
   std::cout << prefix;
   std::cout << " name = " << name;
   std::cout << " foo = " << foo;
   std::cout << " num_vals = " << num_vals; 
   std::cout << " array = { "; 
   for( int index = 0; index < num_vals; ++index ) {
      std::cout << array[index] << " ";
   }
   std::cout << "}";
}


int testClass::run() {
   print( "Before: " );
   std::cout << std::endl; 
   for( int index = 0; index < num_vals; ++index ) {
      array[ index ] += foo;
   } 
   print( "After: " );
   std::cout << std::endl; 
   return SUCCESS;
}

// end of C++ file for testClass
