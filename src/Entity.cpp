#include "Entity.hpp"
Entity::Entity() : Object()
{
	m_name = "Entity";
	AddComponent<Transform>();
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
		if ((*it)->GetID() == component->GetID() && (*it)->GetType() != typeid(Transform).hash_code())
		{
			(*it).reset();
			return true;
		}
	}
	return false;
}

std::shared_ptr<Transform> Entity::transform()
{
	return std::dynamic_pointer_cast<Transform>(components[0]);
}
