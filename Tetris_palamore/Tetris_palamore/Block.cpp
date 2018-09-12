#include "Block.h"


Block::Block()
{
	b = rand() % 7;
	switch (b) {
	case 0:
		block[1] = 1;	block[5] = 1;	block[9] = 1;	block[13] = 1;
		break;
	case 1:
		block[5] = 1;	block[6] = 1;	block[9] = 1;	block[10] = 1;
		break;
	case 2:
		block[5] = 1;	block[6] = 1;	block[7] = 1;	block[9] = 1;
		break;
	case 3:
		block[4] = 1;	block[5] = 1;	block[6] = 1;	block[10] = 1;
		break;
	case 4:
		block[6] = 1;	block[9] = 1;	block[10] = 1;	block[13] = 1;
		break;
	case 5:
		block[5] = 1;	block[9] = 1;	block[10] = 1;	block[14] = 1;
		break;
	case 6:
		block[5] = 1;	block[8] = 1;	block[9] = 1;	block[10] = 1;
		break;
	default:
		break;
	}

}


Block::~Block()
{
}

int* Block::get_block()
{
	return block;
}

void Block::rotate()
{
	int tmp[16];
	memcpy(tmp, block, 64);
	block[0] = tmp[12];	block[1] = tmp[8];	block[2] = tmp[4];	block[3] = tmp[0];
	block[4] = tmp[13];	block[5] = tmp[9];	block[6] = tmp[5];	block[7] = tmp[1];
	block[8] = tmp[14];	block[9] = tmp[10];	block[10] = tmp[6];	block[11] = tmp[2];
	block[12] = tmp[15];	block[13] = tmp[11];	block[14] = tmp[7];	block[15] = tmp[3];

}

void Block::test_printing()
{
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << block[tmp] << " ";
			tmp++;
		}
		cout << endl;
	}
}
