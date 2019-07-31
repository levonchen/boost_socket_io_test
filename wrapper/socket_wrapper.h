#ifndef SOCKET_WRAPPER_H
#define SOCKET_WRAPPER_H


#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <string>

#include <sio_client.h>


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
			
			void setupSocketClient();
			void setupOnReturn();
			
			void on_socket_connected();
			void on_socket_close(client::close_reason const& reson);
			void on_socket_fail();
			
			
		
		private:
		
			bool running;
		
			boost::asio::io_service io;
			boost::asio::deadline_timer timer_;
			
			sio::client m_sioClient;
			bool		m_sioConnected;
		
	};
}

#endif
