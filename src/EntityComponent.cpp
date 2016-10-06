#include "EntityComponent.hpp"

EntityComponent::EntityComponent() : Object()
{

}

EntityComponent::~EntityComponent()
{
	container = nullptr;
}

size_t EntityComponent::GetType()
{
	return typeid(*this).hash_code();
}

std::shared_ptr<Entity> EntityComponent::entity()
{
	return container;
}
