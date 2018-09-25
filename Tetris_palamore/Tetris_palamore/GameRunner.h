#pragma once

#include "value.h"
#include "Block.h"
#include "GameManager.h"
#include "Handler.h"
#include "UIContainer.h"


class GameRunner
{
public:
	GameRunner();
	~GameRunner();

private: 
	GameManager GM;
	Handler		HD;
	UIContainer UC;
	
	DWORD start, end;

	double gap_time = 0;
	double interval = 0;

	int kb_input;
	int tmp;
public:

	void UI_renew_render();

	void Run();

	void get_KB_input();


};

