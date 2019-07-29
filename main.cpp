// #include "iostream"
// using namespace std;
// #define BOOST_ALL_DYN_LINK
// #include "boost/thread.hpp"

// void threadFunc()
// {
	// cout<< "thread hello world!" <<endl;
// }
// int main()
// {
	// boost::function<void()> tdfunc(threadFunc);
	// boost::thread td(tdfunc);
	// td.join();
	
	// return 0;
// }



#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "wrapper/thread_wrapper.h"
#include <string>

using namespace std;
using namespace boost;
using namespace boost::asio;

using namespace socketio_wrapper;

int fun(int x,int y){return x+y;}

void basic_test()
{
	 int m=1;int n=2;
    cout<<boost::bind(fun,_1,_2)(m,n)<<endl;
}


void handler(const boost::system::error_code &ec)
{
	cout<<"1 S." <<std::endl;
}


void asio_test()
{
	boost::asio::io_service io_service;
	boost::asio::deadline_timer time(io_service,boost::posix_time::seconds(1));
	
	time.async_wait(handler);
	
	io_service.run();
	cout<<"Hello world io_service run end"<<std::endl;
}

int main(){
   
   //asio_test();
   
   thread_wrapper rapper;
   
   rapper.Run();
   
   while(true)
   {
	   std::cout<<"Input msg to send, [exit] stop application"<<std::endl;
	   
	   std::string msg;
	   std::cin>>msg;
	   
	   if(msg.compare(exit) == 0)
	   {
		   rapper.Stop();
		   break;
	   }
	   
	   rapper.SendMsg(msg);
   }
    return 0;
}
