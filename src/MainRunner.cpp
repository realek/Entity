//used for testing random crap


#include "Entity.hpp"
#include "Transform.hpp"
#include "LonelyZerglingComponent.h"
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
	//std::cout << "Tried to remove Transform component, status : " << e1.RemoveComponent(ptr) << std::endl;
	e1.SetName("Char");
	e1.AddComponent<LonelyZergling>(); //we are now adding a lonely zergling to our gameObject 
	std::cout<<e1.GetComponent<LonelyZergling>()->entity()->GetName().data()<< " proudly presents the Lonely Zergling  T_T "<<std::endl;
	glm::vec3 zergPos = e1.GetComponent<LonelyZergling>()->entity()->transform()->position;
	std::cout << "Located at coordinates " << zergPos.x << " " << zergPos.y << " " << zergPos.z << std::endl;
	e1.GetComponent<LonelyZergling>()->Burrow();
	std::cout<<"The Lonely Zergling went away with status : "<<e1.RemoveComponent(e1.GetComponent<LonelyZergling>().get())<<std::endl;

	return 0;
}