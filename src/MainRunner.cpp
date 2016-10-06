//used for testing random crap


#include "Entity.hpp"
#include "Transform.hpp"
#include "LonelyZerglingComponent.h"
#include <iostream>
#include <assert.h>
#include <glm\gtc\type_ptr.hpp>
int main() 
{
	std::shared_ptr<Entity> e(std::make_shared<Entity>()), e1(std::make_shared<Entity>()), e2(std::make_shared<Entity>());
	std::cout<<e->GetID()<<" "<<e1->GetID()<<" "<<e2->GetID()<<std::endl;
	e->GetComponent<Transform>()->position = glm::vec3(10.0f,12.0f,5.0f);
	Transform * ptr = e1->GetComponent<Transform>().get();
	assert(ptr != nullptr);
	ptr->position.x = 5.0f;
	ptr->position.y = 4.0f;
	ptr->position.z = 1.0f;
	e1->SetName("Char");
	e1->AddComponent<LonelyZergling>(); //we are now adding a lonely zergling to our gameObject 
	std::cout<<e1->GetComponent<LonelyZergling>()->entity()->GetName().data()<< " proudly presents the Lonely Zergling  T_T "<<std::endl;
	glm::vec3 zergPos = e1->GetComponent<LonelyZergling>()->entity()->transform()->position;
	std::cout << "Located at coordinates " << zergPos.x << " " << zergPos.y << " " << zergPos.z << std::endl;
	e1->GetComponent<LonelyZergling>()->Burrow();
	std::cout<<"The Lonely Zergling went away with status : "<<e1->RemoveComponent(e1->GetComponent<LonelyZergling>().get())<<std::endl;
	e1->GetComponent<Transform>()->SetParent(e);

	//Read matrices
	double LArray[16] = { 0.0 };
	double GArray[16] = { 0.0 };
	const float *pSource = (const float*)glm::value_ptr(e1->GetComponent<Transform>()->LocalTransformMatrix());
	for (int i = 0; i < 16; ++i)
		LArray[i] = pSource[i];

	pSource = (const float*)glm::value_ptr(e1->GetComponent<Transform>()->GlobalTransformMatrix());
	for (int i = 0; i < 16; ++i)
		GArray[i] = pSource[i];

	std::cout << e1->GetName().data() << "'s local transform matrix is :";
	for (int i = 0; i < 16; i=i+4) 
	{
		std::cout << LArray[i] << " " << LArray[i + 1] << " " << LArray[i + 2] << " " << LArray[i + 3]<<std::endl;
	}

	std::cout << e1->GetName().data() << "'s global transform matrix is :";
	for (int i = 0; i < 16; i = i + 4)
	{
		std::cout << GArray[i] << " " << GArray[i + 1] << " " << GArray[i + 2] << " " << GArray[i + 3]<<std::endl;
	}
	return 0;
}