#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <memory>
#include <conio.h>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;

#define MAP_WIDTH	10
#define MAP_HEIGHT	15

typedef struct _pos {
	int		x;
	int		y;

	_pos() {
		x = 0;
		y = 0;
	}
};