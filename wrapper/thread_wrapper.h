
#ifndef THREAD_WRAPPER_H
#define THREAD_WRAPPER_H

#include <boost/shared_ptr.hpp>
#include <thread>
#include <string>
#include "./socket_wrapper.h"

using namespace std;

namespace socketio_wrapper
{
	class thread_wrapper
	{
		public:
			thread_wrapper();			
			~thread_wrapper();
			
		public:
			void Run();
			void Stop();
			
		public:
			
			void SendMsg(const std::string& msg);
			
		private:
			
			boost::shared_ptr<std::thread> m_thread;
			boost::shared_ptr<socket_wrapper> m_socket_wrapper;
	}
}


#endif