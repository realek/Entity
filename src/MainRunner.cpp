//used for testing random crap


#include "Entity.hpp"
#include "EntityComponent.hpp"
#include "Transform.hpp"
#include <iostream>
#include <assert.h>
int main() 
{
	Entity e, e1, e2;
	std::cout<<e.GetID()<<" "<<e1.GetID()<<" "<<e2.GetID()<<std::endl;
	e.AddComponent<EntityComponent>();
	EntityComponent * ptrC = e.GetComponent<EntityComponent>().get();
	
	assert(ptrC!=nullptr);
	std::cout<<"Tried to remove component, status : "<<e.RemoveComponent(ptrC)<<std::endl;
	e1.AddComponent<Transform>();
	Transform * ptr = e1.GetComponent<Transform>().get();
	assert(ptr != nullptr);
	ptr->position.x = 5;
	ptr->position.y = 4;
	ptr->position.z = 1;
	std::cout <<"Transform position vector is :  "<<ptr->position.x << " " << ptr->position.y << " " << ptr->position.z << std::endl;
	std::cout << "Tried to remove Transform component, status : " << e1.RemoveComponent(ptr) << std::endl;

	return 0;
}