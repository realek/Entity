#ifndef ENTITYCOMPONENT_HPP
#define ENTITYCOMPONENT_HPP
#include <stdint.h>
#include "Object.h"
#include <typeinfo>
#include <memory>
class Entity;
class EntityComponent : public Object 
{
public:
	EntityComponent();
	virtual ~EntityComponent();
	size_t GetType();
	std::shared_ptr<Entity> entity();
protected:
	friend class Entity;
	std::shared_ptr<Entity> container;
};

#endif // !ENTITYCOMPONENT_H
