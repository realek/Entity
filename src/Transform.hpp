#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include "EntityComponent.hpp"
#include "Entity.hpp"
#include <glm\vec3.hpp>
#include <glm\matrix.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\euler_angles.hpp>

class Transform : public EntityComponent
{
public:
	Transform();
	virtual ~Transform();
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::mat4 LocalTransformMatrix();
	glm::mat4 GlobalTransformMatrix();
	void SetParent(std::shared_ptr<Entity> Nparent);
	std::shared_ptr<Entity> parent();
private:
	std::shared_ptr<Entity> m_parent;
};

#endif // !TRANSFORM_HPP
