#include "Object.h"

Object::Object()
{
	m_UID = UniqueID::CreateID();
}

Object::~Object()
{
}

uint32_t Object::GetID()
{
	return m_UID;
}
