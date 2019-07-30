cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(boost_socket_io)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

#Set output folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost
             1.70.0
             COMPONENTS thread
                        system
                        log
                        log_setup
                        program_options
             REQUIRED)

include_directories(

${Boost_INCLUDE_DIRS}

)

message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")



aux_source_directory(. DIR_SRCS)

add_executable(demo ${DIR_SRCS})
target_link_libraries(demo ${Boost_LIBRARIES})