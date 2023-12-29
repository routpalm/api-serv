#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
//boost libraries
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>

namespace beast = boost::beast; // <boost/beast.hpp>
namespace http = beast::http; // <boost/beast/http.hpp>
namespace net = boost::asio; // boost::asio
using tcp = net::ip::tcp; // <boost/asio/ip/tcp.hpp>

// Mapping request method types for HTTP request parsing
enum class RequestMethod{ POST, GET, HEAD, PUT, DELETE, 
                        CONNECT, OPTIONS, PATCH, UNDEFINED};
std::map<std::string, RequestMethod> mapRequestMethods ={
    {"POST",RequestMethod::POST},
    {"GET", RequestMethod::GET},
    {"HEAD", RequestMethod::HEAD},
    {"PUT", RequestMethod::PUT},
    {"DELETE", RequestMethod::DELETE},
    {"CONNECT", RequestMethod::CONNECT},
    {"OPTIONS", RequestMethod::OPTIONS},
    {"PATCH", RequestMethod::PATCH},
    {"UNDEFINED", RequestMethod::UNDEFINED}
};

// session class
class Session : public std::enable_shared_from_this<Session>{
    public:
        Session(tcp::socket socket) : socket_(std::move(socket)){
            start();
        }

        void start(){
            // start session internals

        }

    private:
        void read_request(){
            http::async_read(socket_, buffer_, request_, 
                [&](boost::system::error_code ec, std::size_t bytes_transferred){
                    if (!ec){
                        process_request();
                    }else{
                        std::cerr << "error parsing request" << std::endl;
                    }
                });
        }
        void print_request(){
            /*
                Prints HTTP request from listener
            */
            std::cout << "Method: " << request_.method_string() << " | ";
            std::cout << "Target: " << request_.target() << " | ";
            std::cout << "Version: " << request_.version() << std::endl;

            for(auto& header : request_){
                std::cout << "Header: " << header.name_string() << ": " << header.value() << std::endl;
            }

            std::cout << request_.body() << std::endl;

        }
        void process_request(){
            // First, print HTTP request
            std::cout << "request received, printing..." << std::endl;

            print_request();

            switch()
        }
        void send_response();

        tcp::socket socket_;
        beast::flat_buffer buffer_;
        http::request<http::string_body> request_;

};

int main(){
    try{
        // create io context
        net::io_context ioc;

        //create acceptor
        tcp::acceptor acceptor_(ioc, tcp::endpoint(tcp::v4(), 8080));

    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}