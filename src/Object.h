#ifndef OBJECT_H
#define OBJECT_H
#include <stdint.h>
#include "UniqueID.h"
class Object 
{
public:
	Object();
	virtual ~Object();
	uint32_t GetID();
private:
	uint32_t m_UID;
};

#endif // !OBJECT_H
