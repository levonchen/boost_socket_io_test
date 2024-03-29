cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(boost_socket_io)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")    

#Set output folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(DBOOST_ROOT "/usr/local/boost/")
set(DBOOST_LIBRARYDIR "/usr/local/boost/lib/")

set(SIO_CLIENT_INCLUDE_DIRS "/root/socket_cpp/socket.io-client-cpp/build/include")
set(SIO_CLIENT_LIBRARIES "/root/socket_cpp/socket.io-client-cpp/build/lib/Release")


set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost
             1.56.0
             COMPONENTS thread
                        atomic						
                        system
						filesystem
						program_options                        
             REQUIRED)

include_directories(
${Boost_INCLUDE_DIRS}
${SIO_CLIENT_INCLUDE_DIRS}
${CMAKE_CURRENT_LIST_DIR}/rapidjson
#${CMAKE_CURRENT_LIST_DIR}/rapidjson/error
#${CMAKE_CURRENT_LIST_DIR}/rapidjson/internal
#${CMAKE_CURRENT_LIST_DIR}/rapidjson/msinttypes
)

message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")

message(${SIO_CLIENT_INCLUDE_DIRS})
message(${SIO_CLIENT_LIBRARIES})

link_directories(
${SIO_CLIENT_LIBRARIES}
)

aux_source_directory(. DIR_SRCS)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/wrapper DIR_SRCS)

add_executable(demo ${DIR_SRCS})
target_link_libraries(demo ${Boost_LIBRARIES})
target_link_libraries(demo sioclient)

