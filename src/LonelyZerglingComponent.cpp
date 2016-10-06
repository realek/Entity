#include "LonelyZerglingComponent.h"
#include <iostream>
LonelyZergling::LonelyZergling() : EntityComponent()
{
}

LonelyZergling::~LonelyZergling()
{
}

void LonelyZergling::Burrow()
{
	std::cout << "This zergling used Burrow, it was very effective"<<std::endl;
}
