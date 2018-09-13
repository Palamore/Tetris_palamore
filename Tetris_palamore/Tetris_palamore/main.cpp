#include "value.h"
#include "Block.h"
#include "GameManager.h"
#include "Handler.h"
#include "UIContainer.h"

int main() {

	GameManager GM;
	Handler HD;

	HD.H_init(&GM);
	HD.H_D_init();

	HD.H_test_print();
	
	

	return 0;
}