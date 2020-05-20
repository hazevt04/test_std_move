// C++ File for main

#include "my_file_io_funcs.h"
#include "testClass.h"

void usage( const char* prog_name ) {
   printf( "Usage: %s <num values> <-e/--error>\n", prog_name );
   printf( "\n" );
}

void test_testClass() {
   int num_vals = 5;
   std::string name1 = "`96 Bulls";
   std::string name2 = "`93 Bulls";
   int my_array1[5] = { 23, 33, 91, 9, 13 };
   int my_array2[5] = { 23, 33, 54, 10, 24 };
   int foo1 = 3;
   int foo2 = 6;
   int foo3 = 9;

   testClass tc1( name1, foo1, &(my_array1[0]), num_vals );
   testClass tc2( name2, foo2, &(my_array2[0]), num_vals );
   
   tc1.print( "test_testClass(): tc1 before:" );
   std::cout << std::endl;
   
   tc2.print( "test_testClass(): tc2 before:" );
   std::cout << std::endl;
   
   // Move constructor
   testClass tc3(std::move(tc1));

   // Move constructor, alt version
   testClass tc4 = std::move(tc2);

   testClass tc5;
   // Move assignment constructor
   tc5 = std::move(tc3);

   tc1.print( "test_testClass(): tc1 after:" );
   std::cout << std::endl;
   
   tc2.print( "test_testClass(): tc2 after:" );
   std::cout << std::endl;

   tc3.print( "test_testClass(): tc3 after:" );
   std::cout << std::endl;

   tc4.print( "test_testClass(): tc4 after:" );
   std::cout << std::endl;

   tc5.print( "test_testClass(): tc5 after:" );
   std::cout << std::endl;

}


int main( int argc, char** argv ) {
   std::string filename = "foo.bin";
   bool debug = true;
   int num_vals = 10;
   bool inject_error = false;

   std::ostringstream err_msg_stream( std::ostringstream::ate );

   try {
      if ( argc > 2 ) {
         debug_printf( debug, "argv[2] = %s\n", argv[2] ); 
         if ( (!strcmp( argv[2], "-e" )) || (!strcmp( argv[2], "--error" ) ) ) {
            inject_error = true;
         } else {
            err_msg_stream << "Invalid input: " << argv[2];
            throw std::invalid_argument( err_msg_stream.str() );
         }
      } else if ( argc > 1 ) {
         debug_printf( debug, "argv[1] = %s\n", argv[1] ); 
         char* end_ptr = nullptr;
         num_vals = (int)strtoul( argv[1], &end_ptr, 10 );
         if  ( end_ptr == nullptr ) {
            err_msg_stream << "Invalid input: " << argv[1];
            throw std::invalid_argument( err_msg_stream.str() );
         }
      }
      
      std::string foo_str = "foo";
      double foo_double = 3.141592653589793238462f;
      debug_cout( debug, "Testing debug_cout: num_vals is ", num_vals,", foo_str is ", foo_str, ", foo_double is ", foo_double );

      //test_my_file_io_funcs( filename, num_vals, inject_error, debug );
      
      test_testClass();


      return EXIT_SUCCESS;
   
   } catch( std::exception& ex ) {
      printf( "ERROR: %s\n", ex.what() ); 
      return EXIT_FAILURE;
   }
}

