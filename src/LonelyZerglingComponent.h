#ifndef LONELYZERGLINGCOMPONENT_H
#define LONELYZERGLINGCOMPONENT_H
#include "EntityComponent.hpp"
///This is a zergling test component class 
class LonelyZergling : public EntityComponent
{
public:
	LonelyZergling();
	virtual ~LonelyZergling();
	void Burrow();
};

#endif // !LONELYZERGLINGCOMPONENT_H

