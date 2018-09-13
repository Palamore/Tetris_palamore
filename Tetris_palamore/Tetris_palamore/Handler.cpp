#include "Handler.h"



Handler::Handler()
{
}


Handler::~Handler()
{
}

void Handler::H_init(GameManager *GM)  // ���ο� ��� init
{
	Current_moving_block = GM->get_current_block();
	memcpy(Realtime_map, GM->get_map(), 600);
	Block_pos.x = 0;
	Block_pos.y = 0;
}

void Handler::H_D_init()  // �� �����Ӹ��� Realtime_map�� ��� �׷��� ������
{
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

	return true;
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
	if (Block_pos.x < 15)
		Block_pos.x++;
}

void Handler::down()
{
	if(!blocking_check())
	Block_pos.y++;
}

void Handler::drop()
{
}

int * Handler::push_map_render()
{
	return *Realtime_map;		//������ �����ͷ� ���� �� ���ο� �迭 ����.�� �迭�� memcpy���ٰ�
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

