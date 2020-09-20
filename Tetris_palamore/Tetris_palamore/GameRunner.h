#pragma once

#include "value.h"
#include "Block.h"
#include "GameManager.h"
#include "Handler.h"
#include "Renderer.h"
#include "value.h"

class GameRunner
{
public:
	GameRunner();
	~GameRunner() = default;
	void RenderMap();
	void Run();
	void GetKeyboardInput();
private:
	GameManager GM;
	Handler	HD;
	Renderer RD;
	DWORD start, end;
	int mInput;
	int mBlockTouchedFlag;

};

