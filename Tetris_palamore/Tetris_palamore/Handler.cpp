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
	memcpy(Current_stacked_map, GM->get_map(), 600);
	Block_pos.x = 0;
	Block_pos.y = 0;
}

void Handler::H_D_init(GameManager *GM)  // �� �����Ӹ��� Realtime_map�� ��� �׷��� ������
{
	Current_moving_block = GM->get_current_block();
	memcpy(Realtime_map, GM->get_map(), 600);
	int* block_tmp = Current_moving_block->get_block();
	int  block_tmp2[16];
	int tmp = 0;
	memcpy(block_tmp2, block_tmp, 64);
	for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
		for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
			if (block_tmp2[tmp] == 1)
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
					//				cout << "i == 14 excuted " << endl;
					return true;
				}

				if (Current_stacked_map[i + 1][j] == 1) {
					//				cout << " i + 1 == 1 excuted" << endl;
					return true;
				}

			}
			tmp++;
		}
	}
	return false;
}

bool Handler::blocking_check_side(int a)
{

	int* block_tmp = Current_moving_block->get_block();
	int block_tmp2[16];
	memcpy(block_tmp2, block_tmp, 64);
	int tmp = 0;
	if (a == 1) {

		for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
			for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
				if (block_tmp2[tmp] == 1) {
					if (j == 0)
						return true;

					if (Current_stacked_map[i][j - 1] == 1) {
						//				cout << " i + 1 == 1 excuted" << endl;
						return true;
					}

				}
				tmp++;
			}
		}
	}
	else {
		for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
			for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
				if (block_tmp2[tmp] == 1) {
					if (j == 9)
						return true;

					if (Current_stacked_map[i][j + 1] == 1) {
						//				cout << "  + 1 == 1 excuted" << endl;
						return true;
					}

				}
				tmp++;
			}
		}
	}
	return false;
}

void Handler::on_the_map_check()
{
	int* block_tmp = Current_moving_block->get_block();
	int block_tmp2[16];
	memcpy(block_tmp2, block_tmp, 64);
	int tmp = 0;
	for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
		for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
			if (block_tmp2[tmp] == 1) {
				if (j < 0) {
					Block_pos.x++;
					return;
				}
				if (j > 9) {
					Block_pos.x--;
					return;
				}
			}
			tmp++;
		}
	}

}

bool Handler::rotate_check()
{
	int* block_tmp = Current_moving_block->get_block();
	int block_tmp2[16];
	memcpy(block_tmp2, block_tmp, 64);
	int tmp = 0;
	for (int i = Block_pos.y; i < Block_pos.y + 4; i++) {
		for (int j = Block_pos.x; j < Block_pos.x + 4; j++) {
			if (block_tmp2[tmp] == 1) {
				if (Current_stacked_map[i][j] == 1) {
					return false;
				}
			}
			tmp++;
		}
	}
	return true;
}

void Handler::make_rotate()
{
	Current_moving_block->rotate();
	on_the_map_check();
	on_the_map_check();
	if (!rotate_check()) {
		Current_moving_block->reverse_rotate();
	}
}

void Handler::move_left()
{
	if (!blocking_check_side(1))
		Block_pos.x--;
}

void Handler::move_right()
{
	if (!blocking_check_side(2))
		Block_pos.x++;
}

// ����� ���� ���� ������ Running���� down�� ���ϰ��� ���� ����.
int Handler::down()    // down�� �����ϴ� ���� ���� down�ϴ��� ���� �����ϴ��� ����.
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
	return *Realtime_map;		//������ �����ͷ� ���� �� ���ο� �迭 ����.�� �迭�� memcpy���ٰ�
}
