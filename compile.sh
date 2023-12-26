make
install_name_tool -change @rpath/libboost_system.dylib ../boost/stage/lib/libboost_system.dylib server
install_name_tool -change @rpath/libboost_thread.dylib ../boost/stage/lib/libboost_thread.dylib server
install_name_tool -change @rpath/libboost_system.dylib ../boost/stage/lib/libboost_system.dylib client
install_name_tool -change @rpath/libboost_thread.dylib ../boost/stage/lib/libboost_thread.dylib client