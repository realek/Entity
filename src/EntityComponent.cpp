#include "EntityComponent.hpp"

EntityComponent::EntityComponent() : Object()
{

}

EntityComponent::~EntityComponent()
{
}

size_t EntityComponent::GetType()
{
	return typeid(*this).hash_code();
}
