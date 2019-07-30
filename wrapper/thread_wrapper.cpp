
#include "thread_wrapper.h"
#include<iostream>

using namespace socketio_wrapper;
using namespace std;



thread_wrapper::thread_wrapper()
{

}
thread_wrapper::~thread_wrapper()
{
	//Stop();
}

void thread_wrapper::Run()
{
	m_socket_wrapper.reset(new socket_wrapper());
	m_thread.reset(new std::thread(&socket_wrapper::Run,m_socket_wrapper);
}
void thread_wrapper::Stop()
{
	m_socket_wrapper->Stop();
	if(m_thread->joinable())
		m_thread->join();
	
	std::cout<<"socket_wrapper  stopped"<<std::endl;
	m_socket_wrapper.reset();
	m_thread.reset();
	
}


void thread_wrapper::SendMsg(const std::string& msg)
{
	m_socket_wrapper->GetIO()->post([&,msg]{
		
		m_socket_wrapper->SendMsg(msg);
	});
}