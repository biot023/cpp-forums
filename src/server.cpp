#include <iostream>
#include <stdexcept>
#include <getopt.h>
#include <boost/network/protocol/http/server.hpp>
#include <string>

using namespace std;

int main( const int argc, const char *argv[] )
{
  int port( 80 );
  try {
    cout << "******** Hello from the future server app!" << endl;
  } catch ( const exception &e ) {
    cout << "Error: " << e.what() << endl;
    cerr << "Error: " << e.what() << endl;
    exit( 1 );
  }
  return 0;
}
