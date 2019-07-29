#include "iostream"
using namespace std;
#define BOOST_ALL_DYN_LINK
#include "boost/thread.hpp"

void threadFunc()
{
	cout<< "thread hello world!" <<endl;
}
int main()
{
	boost::function<void()> tdfunc(threadFunc);
	boost::thread td(tdfunc);
	td.join();
	
	return 0;
}
