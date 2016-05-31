#ifndef ADDITION_H
#define ADDITION_H

#include <stdio.h>
#include <stdlib.h>
#include "str.h"

#define string_size 261
	enum Errors
	{
		NO_ERROR = 0,
		ERROR
	};

    int input(char *s, char *d1, char *d2);
    void process(char *s, char d1, char d2);
    int check(char *s);
    
#endif
