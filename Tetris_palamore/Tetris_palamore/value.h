#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <vector>
using namespace std;

#define STAGE_WIDTH		10
#define STAGE_HEIGHT	15

typedef struct _pos {
	int		x;
	int		y;


	_pos() {
		x = 0;
		y = 0;
	}


};