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



#include<iostream>
#include<boost/bind.hpp>
using namespace std;
using namespace boost;

int fun(int x,int y){return x+y;}
int main(){
    int m=1;int n=2;
    cout<<boost::bind(fun,_1,_2)(m,n)<<endl;
    return 0;
}
