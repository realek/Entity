#include "Transform.hpp"
#include <iostream>
Transform::Transform() : EntityComponent()
{
	position = { 0.0f,0.0f,0.0f };
	rotation = { 0.0f,0.0f,0.0f };
	scale = { 0.0f,0.0f,0.0f };
}

Transform::~Transform()
{

	m_parent = nullptr;
}

glm::mat4 Transform::LocalTransformMatrix()
{
	glm::mat4 rotmat = glm::eulerAngleZ(rotation.z) * glm::eulerAngleY(rotation.y) * glm::eulerAngleX(rotation.x);
	return glm::scale(glm::translate(glm::mat4(1), position)*rotmat, scale);
}

glm::mat4 Transform::GlobalTransformMatrix()
{
	if (m_parent != nullptr)
		return m_parent->transform()->GlobalTransformMatrix()*LocalTransformMatrix();
	else
		return LocalTransformMatrix();
}

void Transform::SetParent(std::shared_ptr<Entity> Nparent)
{
	if (Nparent == nullptr)
		m_parent = nullptr;
	else
		m_parent = Nparent;
}

std::shared_ptr<Entity> Transform::parent()
{
	return m_parent;
}
