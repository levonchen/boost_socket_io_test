#ifndef SOCKET_WRAPPER_H
#define SOCKET_WRAPPER_H

#include <boost\asio\io_service.hpp>
#include <boost\bind.hpp>
#include <boost\asio.hpp>
#include <string>


namespace socketio_wrapper
{
	
	class socket_wrapper
	{
		public:
			socket_wrapper();
			~socket_wrapper();
			
		public:
		
			void Run();
			void Stop();
			
			boost::asio::io_service* GetIO() { return &io;}
			
		public:
		
			void SendMsg(const std::string& msg);
			
		private:
			void onTick();
		
		private:
		
			bool running;
		
			boost::asio:io_service io;
			boost::asio::deadline_timer timer_;
		
	}
}

#endif