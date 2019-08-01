
#ifndef SOCKET_OBJECTS_H
#define SOCKET_OBJECTS_H

#include <string>
#include <array>

#include "../rapidjson/prettywriter.h"

using namespace std;

namespace socketio_wrapper
{
	
	class CParams
	{
		public:
			int count;
			std::string msg;
			std::array< std::array<int> > datas;
			
		public:
		
			template<typename Writer>
			void Serialize(Writer& writer) const{
				
				writer.String("count");
				writer.Uint(count);

				writer.String("msg");
				writer.String(msg);
				
			}
	}
}

#endif