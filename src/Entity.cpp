#include "Entity.hpp"
Entity::Entity() : Object()
{
}

Entity::~Entity()
{
}


std::string Entity::GetName()
{
	return m_name;
}

void Entity::SetName(std::string name)
{
	m_name = name;
}

bool Entity::RemoveComponent(EntityComponent * component)
{
	for (auto it = components.begin(); it != components.end(); ++it) 
	{
		if ((*it)->GetID() == component->GetID()) 
		{
			(*it).reset();
			return true;
		}
	}
	return false;
}

