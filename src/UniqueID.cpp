#include "UniqueID.h"

uint32_t UniqueID::m_lastId = 0;

uint32_t UniqueID::CreateID()
{
	return ++m_lastId;
}

UniqueID::~UniqueID()
{
}
