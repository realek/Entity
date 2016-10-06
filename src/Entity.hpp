#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stdint.h>
#include "Object.h"
#include "EntityComponent.hpp"
#include <vector>
#include <memory>
#include <typeinfo>
class Entity : public Object
{
public:
	Entity();
	virtual ~Entity();
	std::string GetName();
	void SetName(std::string name);
	template <class T> void AddComponent();
	template <class T> std::shared_ptr<T> GetComponent();
	bool RemoveComponent(EntityComponent * component);
private:
	std::string m_name;
	//using vector until I implement a simple linked list, double list in std is overkill
	std::vector<std::shared_ptr<EntityComponent>> components;
};

template<class T>
inline void Entity::AddComponent()
{
	components.push_back(std::make_shared<T>());
}

template<class T> inline std::shared_ptr<T> Entity::GetComponent()
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		if ((*it)->GetType() == typeid(T).hash_code())
		{
			return std::dynamic_pointer_cast<T>(*it);
		}
	}
	return nullptr;
}

#endif // !ENTITY_H


