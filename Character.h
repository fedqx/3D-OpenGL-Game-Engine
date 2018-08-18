#pragma once
#include "EngineObject.h"
class Character : public EngineObject
{
public:
	short health;
	short stamina;
	
	Character();
	~Character();
};

