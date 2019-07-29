cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(boost_socket_io)

set(BOOST_INCLUDEDIR "/root/boost/boost_1_70_0")
set(BOOST_LIBRARYDIR "/root/boost/boost_1_70_0/libs")

set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)



include_directories(

${BOOST_INCLUDEDIR}

)

link_directories(
${BOOST_LIBRARYDIR}
)

link_libraries(
thread
)


aux_source_directory(. DIR_SRCS)

add_executable(demo ${DIR_SRCS})
target_link_libraries(demo thread)