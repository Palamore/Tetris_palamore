#pragma once

#include "value.h"
#include "Handler.h"

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;

	void GetMapValue(Handler* HD);
	void Render();

private:
	int mRenderInfo[15][10] = { 0, };
};

