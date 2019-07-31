#include "socket_wrapper.h"
#include <iostream>


using namespace socketio_wrapper;
using namespace std;

static const boost::posix_time::seconds interval(5);

socket_wrapper::socket_wrapper()
	:timer_(io,interval),
	running(true)
{
	m_sioConnected = false;
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

void socket_wrapper::setupSocketClient()
{	
	m_sioClient.set_open_listener(std::bind(&socket_wrapper::on_socket_connected, this));
    m_sioClient.set_close_listener(std::bind(&socket_wrapper::on_socket_close, this,std::placeholders::_1));
    m_sioClient.set_fail_listener(std::bind(&socket_wrapper::on_socket_fail, this));
	
	m_sioClient.connect("http://192.169.1.100:9000");
}

void socket_wrapper::setupOnReturn()
{
	m_sioClient.socket()->on("SkeletonResult",sio::socket::event_listener_aux([&](string const& name, message::ptr const& data, bool isAck,message::list &ack_resp){
		
		std::cout<<"On Return From Server: "<< name <<std::endl;
		
		
	});
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
	
	//set up client
	setupSocketClient();
	
	while(running)
	{
		io.run_one();
	}
	
	std::cout<<"socket_wrapper::Run ----- end"<<std::endl;
}


void socket_wrapper::SendMsg(const std::string& msg)
{
	std::cout<<"Send to server:" << msg<< std::endl;
	
	if(m_sioConnected){
		m_sioClient.socket()->emit("SkeletonResult",msg);
	}
}

void socket_wrapper::on_socket_connected()
{
	m_sioConnected = true;
	
	setupOnReturn();
	
}
void socket_wrapper::on_socket_close(client::close_reason const& reson)
{
	std::cout<<"sio closed "<<std::endl;
	m_sioConnected = false;
}
void socket_wrapper::on_socket_fail()
{
	std::cout<<"sio fail "<<std::endl;
	m_sioConnected = false;
}