#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include "EntityComponent.hpp"
#include <glm\vec3.hpp>
class Transform : public EntityComponent
{
public:
	Transform();
	virtual ~Transform();
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
};

#endif // !TRANSFORM_HPP
