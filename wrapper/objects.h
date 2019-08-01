
#ifndef SOCKET_OBJECTS_H
#define SOCKET_OBJECTS_H

#include <string>
#include <vector>

#include "../rapidjson/prettywriter.h"

using namespace std;

namespace socketio_wrapper
{
	
	class CParams
	{
		public:
			int count;
			std::string msg;
			std::vector< std::vector<int> > datas;
			
		public:
		
			template<typename Writer>
			void Serialize(Writer& writer) const{
				
				writer.String("count");
				writer.Uint(count);

				writer.String("msg");
				writer.String(msg);
				
			}
	};
}

#endif