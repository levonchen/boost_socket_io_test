
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
				
				writer.StartObject();
				
				writer.String("count");
				writer.Uint(count);

				writer.String("msg");
				writer.String(msg);
				
				writer.String("datas");
				writer.StartArray();
					for(std::vector< std::vector<int> >::const_iterator it = datas.begin();
						it != datas.end();
						++it)
						{
							std::vector<int> par = *it;
							writer.StartArray();
								for(std::vector<int>::const_iterator itSub = par.begin();
									itSub != par.end();
									++itSub)
									{
										writer.Int(*itSub);
									}
							writer.EndArray();
						}
				
				writer.EndArray();
				
				writer.EndObject();
				
			}
	};
}

#endif