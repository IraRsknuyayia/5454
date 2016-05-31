#include "addition.h"
#include "str.h"

int input(char *s, char *d1, char *d2)
{
    printf("Symbol1 : ");
    fgets(d1, 2, stdin);// S4itivaem sym
    __fpurge(stdin);// 4istim potok dannih
	printf("Symbol2 : ");
    fgets(d2, 2, stdin);
    __fpurge(stdin);
    printf("Path : ");
    fgets(s, (string_size + 1), stdin);// s4itivaem stroky
    __fpurge(stdin);
    int size = slen(s);// dlina stroki
    
    *(s + size - 1) = '\0';// change '\n' to '\0'
    return size;

}

int check(char *s)
{
    char d_ru[] = "ru";
    char d_com[] = "com";
    char d_org[] = "org";
    char err_sym[] = {':', '*', '?', '<', ' ', '>', '|', '"', '\\', '@', ',', ';', '#', '$', '%', '^', '&', '(', ')', '\0'};
    char IP_num[]="0123456789";
    char prot_h[] = "http:";
    char prot_s[] = "smb:";
    char prot_f[] = "ftp:";
    char prot_r[] = "rsync:";

    int i;
    int count_dot, count_slash;
    char *slash_ptr[120], *dot_ptr[25];

    /* Length of string */
    if (slen(s) == 0) {
        fprintf(stderr, "Is URL: no\n");
        return ERROR;
    }
    
    /* Length of string >= 261 */
    if (slen(s) >= string_size) {
        fprintf(stderr, "Is URL: no\n");
        return ERROR;
    }

    count_slash = stok(s, '/', slash_ptr);//delim put` po slasham
    // esli malo slashey
    if (count_slash < 4) {
		fprintf(stderr, "Is URL: no\n");
		return ERROR;
	}
    
    // Check slashes polojenie
    if ((slash_ptr[1] != (slash_ptr[2] - 1)) || slash_ptr[0] == (slash_ptr[1] - 1)) {
		fprintf(stderr, "Is URL: no\n");
		return ERROR;
	}
    
    // Check protocols
    if ((scmp(*slash_ptr, prot_f) != 0) && (scmp(*slash_ptr, prot_h) != 0) &&
	    (scmp(*slash_ptr, prot_r) != 0)  && (scmp(*slash_ptr, prot_s) != 0)) {
			fprintf(stderr, "Is URL: no\n");
			return ERROR;
		}
    
    printf("Is URL: yes\n");
    
    //check domain
    count_dot = stok(slash_ptr[2], '.', dot_ptr);
    if (count_dot == 1) {
		fprintf(stderr, "Domain name is correct: no\n");
		return ERROR;
	}
	
	// roverka addressa
	for (i = 0; i < (count_dot - 1); i++) {
		if (scspn(dot_ptr[i], err_sym) >= 0) {
			fprintf(stderr, "Domain name is correct: no\n");
			return ERROR;
		}
		if (sspn(dot_ptr[i], IP_num) >= 0) {
			fprintf(stderr, "Domain name is correct: no\n");
			return ERROR;
		}
	}
	
	// proverka domain
	if ((sequal(dot_ptr[(count_dot - 1)], d_ru) == 0) &&
		(sequal(dot_ptr[(count_dot - 1)], d_com) == 0) &&
		(sequal(dot_ptr[(count_dot - 1)], d_org) == 0)) {
			fprintf(stderr, "Domain name is correct: no\n");
			return ERROR;
		}
	
	suntok(slash_ptr[2], '.', dot_ptr, count_dot);
	printf("Domain name is correct: yes \n");
	
	// Check path of file
	if (slen(slash_ptr[3]) == 0) {
		fprintf(stderr, "File path: no\n");
		return ERROR;
		}
	
	for (i = 3; i < count_slash; i++) {
		if (slen(slash_ptr[i]) == 0 && (i + 1 != count_slash)) {
			fprintf(stderr, "File path: no\n");
			return ERROR;
		}
		if (sspn(slash_ptr[i], err_sym) >= 0 && (*slash_ptr[i] != '\0')) {
			fprintf(stderr, "File path: no\n");
			return ERROR;
		}
	}
	
	suntok(s, '/', slash_ptr, count_slash);
    return NO_ERROR;
}

void process(char *s, char d1, char d2)
{
	char *ptr[100], *ptr_d[100];
	int d, count = stok(s, '/', ptr);// delim file path na podputi
	int i;
	for (i = 0; i < count; i++) {
		d = stok(ptr[i], d1, ptr_d); // delim podput` po sym1
		suntok(ptr[i], d2, ptr_d, d);// skleivaem podput` po sym2
	}
	suntok(s, '/', ptr, count);
}
