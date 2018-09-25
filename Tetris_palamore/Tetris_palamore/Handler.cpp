#include "Handler.h"



Handler::Handler()
{
}


Handler::~Handler()
{
}

void Handler::H_init(GameManager *GM)  // 새로운 블록 init
{

	Current_moving_block = GM->get_current_block();
	memcpy(Realtime_map, GM->get_map(), 600);
	memcpy(Current_stacked_map, GM->get_map(), 600);
	Block_pos.x = 0;
	Block_pos.y = 0;
}

void Handler::H_D_init(GameManager *GM)  // 매 프레임마다 Realtime_map에 블록 그래픽 덮어씌우기
{
	Current_moving_block = GM->get_current_block();
	memcpy(Realtime_map, GM->get_map(), 600);
	int* block_tmp = Current_moving_block->get_block();
	int  block_tmp2[16];
	int tmp = 0;
	memcpy(block_tmp2, block_tmp, 64);
	for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
		for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
			if(block_tmp2[tmp] == 1)
			Realtime_map[i][j] = 1;
			tmp++;
		}
	}
}

bool Handler::blocking_check()
{

	int* block_tmp = Current_moving_block->get_block();
	int block_tmp2[16];
	memcpy(block_tmp2, block_tmp, 64);
	int tmp = 0;
	for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
		for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
			if (block_tmp2[tmp] == 1) {
				if (i == 14) {
					cout << "i == 14 excuted " << endl;
					return true;
				}

				if (Current_stacked_map[i + 1][j] == 1) {
					cout << " i + 1 == 1 excuted" << endl;
					return true;
				}

			}
			tmp++;
		}
	}
	return false;  // 실험중 원래 true임
}

void Handler::make_rotate()
{
	Current_moving_block->rotate();
}

void Handler::move_left()
{
	if (Block_pos.x > 0)
		Block_pos.x--;
}

void Handler::move_right()
{
	if (Block_pos.x < 7)
		Block_pos.x++;
}

// 블록이 쌓인 후의 로직은 Running에서 down의 리턴값에 따라서 결정.
int Handler::down()    // down이 리턴하는 값에 따라서 down하느냐 맵을 갱신하느냐 결정.
{
	if (!blocking_check()) {
		Block_pos.y++;
		return 0;
	}
	else {
		cout << "Blocked !! " << endl;
		return 1;
	}
	
}

void Handler::drop()
{
	while (!down());
}

Block Handler::get_Current_block()
{
	return *Current_moving_block;
}

int Handler::get_x()
{
	return Block_pos.x;
}

int Handler::get_y()
{
	return Block_pos.y;
}

int * Handler::push_map_render()
{
	return *Realtime_map;		//받을때 포인터로 받은 후 새로운 배열 생성.그 배열로 memcpy해줄것
}

void Handler::H_test_print()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			cout << Realtime_map[i][j];
		}
		cout << endl;
	}
}

