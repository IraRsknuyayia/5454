#ifndef STR_H
#define STR_H

    int slen(char *s);// Length of string
    int scmp(char *s1, char *s2);// Comparing strings in alphabetical order
    int sequal(char *s1, char *s2);// Equity strings
    int stok(char str[], char delim, char *ptr[]);// count of delims
    int schr(char *s, char delim);// find of symbol
    int sspn(char str[], char sym[]);// valid symbols
    int scspn(char str[], char nsym[]);// not valid symbols
    void scopy(char *s1, char *s2);
    void suntok(char str[], char delim, char *ptr[], int cnt);
    int atoi_str(char *str);// char to int

#endif // STR_H
