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

}
