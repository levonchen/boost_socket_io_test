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
#include "wrapper/objects.h"
#include <string>

#include "rapidjson/prettywriter.h" 

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
   
   thread_wrapper wrapper;
   
   wrapper.Run();
   
   int count = 1;
   while(true)
   {
	   std::cout<<"Input msg to send, [exit] stop application"<<std::endl;
	   
	   std::string msg;
	   std::cin>>msg;
	   
	   if(msg.compare("exit") == 0)
	   {
		   wrapper.Stop();
		   break;
	   }
	   
	   CParams params;
	   params.count = count++;
	   params.msg = msg;
	   
	   StringBuffer sb;
	   PrettyWriter<StringBuffer> writer(sb);
	
	   params.Serialize(writer);
	   
	   std::string output = sb.GetString();
	   
	   wrapper.SendMsg(output);
   }
    return 0;
}
