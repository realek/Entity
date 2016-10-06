#ifndef UNIQUEID_H
#define UNIQUEID_H

#include<stdint.h>

class UniqueID
{
public:
	static uint32_t CreateID();
private:
	//add serializer/deserializer class as friend
	UniqueID();
	~UniqueID();
	static uint32_t m_lastId;
};

#endif // !UNIQUEID_H

