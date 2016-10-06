#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stdint.h>
#include "Object.h"
#include "Transform.hpp"
#include <vector>
#include <memory>
#include <typeinfo>

class Transform;
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
	std::shared_ptr<Transform> transform();

private:
	std::string m_name;
	std::vector<std::shared_ptr<EntityComponent>> components;
};

template<class T> inline void Entity::AddComponent()
{
	components.push_back(std::make_shared<T>());
	components[components.size() - 1]->container = std::make_shared<Entity>(*this);
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


