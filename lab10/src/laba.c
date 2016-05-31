#include "addition.h"

/* Function uses all functions */
int main()
{
    char str[string_size];
    int size;
	char d1, d2;
	size = input(str, &d1, &d2); // Вводим строку и получаем её длину

    if (!check(str)) {
		process(str, d1, d2);
    } else {
		return EXIT_SUCCESS;
	}

    printf("Result\t%s\n", str);
    return EXIT_SUCCESS;
}

