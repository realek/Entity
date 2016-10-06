#ifndef ENTITYCOMPONENT_HPP
#define ENTITYCOMPONENT_HPP
#include <stdint.h>
#include "Object.h"
#include <typeinfo>
class EntityComponent : public Object 
{
public:
	EntityComponent();
	virtual ~EntityComponent();
	size_t GetType();
private:
};

#endif // !ENTITYCOMPONENT_H
