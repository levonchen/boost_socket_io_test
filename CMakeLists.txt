cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(boost_socket_io)

set(boostroot "/root/boost/boost_1_70_0")
set(boostrootlib "/root/boost/boost_1_70_0/libs")

include_directories(
	${boostroot}
)

aux_source_directory(. DIR_SRCS)

add_executable(demo ${DIR_SRCS})
target_link_libraries(demo ${boostrootlib})