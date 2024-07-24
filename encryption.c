#include <cstddef>
#include <stdio.h>

int CheckInput(char* av1, char* av2);
int Encrypt(char* av1, char* av2);

int
main(int argc, char* argv[]) {
	int checkedInput = CheckInput(argv[1], argv[2]);
	switch (checkedInput) {

	case 1:
		puts("arg1 can't be type: NULL'");
		break;
	
	case 2:
		puts("arg2 can't be type: NULL'");
		break;

	default:
		break;

	}

	Encrypt(argv[1], argv[2]);

	return 0;
}

int
CheckInput(char* av1, char* av2) {
	if (av1 == NULL)
		return 1;

	if (av2 == NULL)
		return 2;

	return 0;
}

int
Encrypt(char* av1, char* av2) {
	return 0;
}
