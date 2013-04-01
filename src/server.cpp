#include <iostream>
#include <stdexcept>
#include <getopt.h>
#include <boost/network/protocol/http/server.hpp>
#include <string>

using namespace std;
namespace http = boost::network::http;

struct Handler;
using server_t = http::server<Handler>;

struct Handler
{
  void operator() ( const server_t::request &request, server_t::response & response )
  {
    response = server_t::response::stock_reply( server_t::response::ok,
                                                "<html><body><h1>Hello.</h1></body></html>" );
  }
};

int main( int argc, char *argv[] )
{ 
  try {
    string address( "0.0.0.0" );
    string port( "80" );
    static struct option long_options[] = {
      { "address", required_argument, nullptr, 'a' },
      { "port", required_argument, nullptr, 'p' }
    };
    int opt_index( 0 );
    int opt( getopt_long( argc, argv, "", long_options, &opt_index ) );
    while ( opt != -1 ) {
      switch( opt ) {
        case 'a': address = optarg; break;
        case 'p': port = optarg; break;
        default: throw runtime_error( "Unhandled option" ); break;
      } // esac
    } // wend
    Handler handler;
    server_t server( address, port, handler );
    server.run();
    cout << "Running at 0.0.0.0:" << port << endl;
  } catch ( const exception &e ) {
    cout << "Error: " << e.what() << endl;
    cerr << "Error: " << e.what() << endl;
    exit( 1 );
  }
  return 0;
}
