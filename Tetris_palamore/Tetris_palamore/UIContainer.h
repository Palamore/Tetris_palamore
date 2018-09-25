#pragma once

#include "value.h"
#include "Handler.h"

class UIContainer
{
public:
	UIContainer();
	~UIContainer();

private:

	int Map_value[15][10];

public:

	void get_Map_value(Handler *HD);

	void Render();



};

