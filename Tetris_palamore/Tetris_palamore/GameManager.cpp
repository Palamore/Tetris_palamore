#include "GameManager.h"



GameManager::GameManager()
{
	for (int i = 0; i < 3; i++) {
		Block_maker = new Block();
		Block_q.push(*Block_maker);
	}
	Current_handled_block = new Block();//���� slot_rotate ������� delete�� ���� ���̺�
	slot_rotate();

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			Current_map[i][j] = 0;
		}
	}
	//	Current_map[0][0] = 1; 

}


GameManager::~GameManager()
{
}

void GameManager::slot_rotate()
{
	//	delete Current_handled_block;	//���� �ڵ鿡 �ִ� �� ����Ʈ
	Block_maker = new Block();		//���ο� �� ����
	Block_q.push(*Block_maker);		//���� ť�ȿ� Ǫ��
	Current_handled_block = &Block_q.front();	// ť�� ���� ���� ���� �ڵ������ͷ� ����
	Block_q.pop();					//ť�� ���� ���� ���� ��.
	Next_block = &Block_q.front();  //���� ���� next block �����ͷ� ����.
}

void GameManager::all_the_line_down(vector<int> v)
{
	vector<int>::iterator it;
	it = v.begin();
	int empty[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int tmp = v.size();
	for (int i = 0; i < tmp; i++) {
		for (int j = (*it) - 1; j >= 0; j--) {
			memcpy(Current_map[j + 1], Current_map[j], 40);
			//	Current_map[j + 1] = Current_map[j];
		}
		memcpy(Current_map[0], empty, 40);
		it++;
	}
}

void GameManager::line_clear()
{
	vector<int> v;
	int empty[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int tmp[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for (int i = 0; i < 15; i++) {
		if (memcmp(Current_map[i], tmp, 40) == 0) {
			v.push_back(i);
			score += 100;
		}
	}
	all_the_line_down(v);

}

void GameManager::renew_map(int x, int y, int block[])
{
	int tmp = 0;
	for (int i = y - 1; i < y + 3; i++) { // x,y�� �ּҰ��� 1�̱⶧���� �ε����� ����.
		for (int j = x - 1; j < x + 3; j++) {
			if (block[tmp])
				Current_map[i][j] = 1;
			tmp++;
		}
	}

}

Block * GameManager::get_current_block()
{
	return Current_handled_block;
}

Block * GameManager::get_next_block()
{
	return Next_block;
}

int * GameManager::get_map()
{
	return *Current_map;		//������ �����ͷ� ���� �� ���ο� �迭 ����.�� �迭�� memcpy���ٰ�
}
