#include <iostream>
#include <cstdlib>
#include <string>
//boost libraries
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast; // <boost/beast.hpp>
namespace http = beast::http; // <boost/beast/http.hpp>
namespace net = boost::asio; // boost::asio
using tcp = net::ip::tcp; // <boost/asio/ip/tcp.hpp>

int main(){

    try{
        boost::asio::io_context io;
        

    }catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}