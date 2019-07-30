#include "socket_wrapper.h"
#include<iostream>
using namespace socketio_wrapper;
using namespace std;

static const boost::posix_time::seconds interval(1);

socket_wrapper::socket_wrapper()
	:timer_(io,interval),
	running(true)
{
	std::cout<<"socket_wrapper created"<<std::endl;
}

socket_wrapper::~socket_wrapper()
{
	std::cout<<"socket_wrapper destroyed"<<std::endl;
}

void socket_wrapper::Stop()
{
	running = false;
}

void socket_wrapper::onTick()
{
	std::cout<<"onTick"<<std::endl;
	
	timer_.expires_at(timer_.expires_at() + interval);
	timer_.async_wait(boost::bind(&socket_wrapper::onTick,this));
}

void socket_wrapper::Run()
{
	std::cout<<"socket_wrapper::Run ----- start"<<std::endl;
	
	onTick();
	
	while(running)
	{
		io.run_one();
	}
	
	std::cout<<"socket_wrapper::Run ----- end"<<std::endl;
}


void socket_wrapper::SendMsg(const std::string& msg)
{
	std::cout<<"Send to server:" << msg<< std::endl;
}