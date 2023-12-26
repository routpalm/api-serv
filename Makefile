COMPILER=g++
OPTIONS=-std=c++11 -Wall -stdlib=libc++ -lboost_system -lboost_thread
INCLUDECLIENT=/Users/nichilus/vscode/api-serv/boost client.cpp
INCLUDESERV=/Users/nichilus/vscode/api-serv/boost server.cpp
OUT=out
LIBRARIES=../boost/stage/lib

all: client server

client: client.cpp
	g++ $(OPTIONS) -I $(INCLUDECLIENT) -L $(LIBRARIES) -o client

server: server.cpp
	g++ $(OPTIONS) -I $(INCLUDESERV) -L $(LIBRARIES) -o server

clean:
	rm -f client server