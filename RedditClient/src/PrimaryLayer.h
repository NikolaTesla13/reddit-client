#pragma once

#include "Walnut\Layer.h"

class PrimaryLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override;

	void ShowWelcomeScreen();	
};