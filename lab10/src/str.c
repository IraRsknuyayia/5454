#include "str.h"
#include <stdio.h>

/* Return length of string */
int slen(char *s)
{
    int i = 0;
    for (i; *(s+i) != '\0'; i++);
    return i;
}

/* Copy string "s1" to string "s2" */
void scopy(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
        s2[i] = s1[i];
    s2[i] = '\0';
}

/* Return '1' if s1 == s2, else return '0' if s1 !=s2 */
int sequal(char *s1, char *s2)
{
    int i, flg = 1;
    for(i = 0; flg && (s1[i]!='\0' || s2[i]!='\0'); i++) {
        if( s1[i] != s2[i] )
            return flg = 0;
    }
    return flg;
}

/* Return '0' if s1 == s2; return '-1' if s1 < s2'; return '1' if s1 > s2 */
int scmp(char *s1, char *s2)
{
    int i, flg = 0;
        for(i = 0; (s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0'; i++);
            if( s1[i] < s2[i] )
                flg = -1;
            else if( s1[i] > s2[i] )
                flg = 1;
}

/* Return count of delims and change delim on '\0' */
int stok(char str[], char delim, char *ptr[])
{
    char *suf = str;
    ptr[0] = str;
    int i, j = 1;

    while( ( i = schr(suf, delim) ) >= 0 ) {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}

/* Change '\o' on delim */
void suntok(char str[], char delim, char *ptr[], int cnt)
{
    int i;
    for(i = 1; i < cnt; i++) {
        *(ptr[i] - 1) = delim;
    }
}

/* Return index of delim or return "-1" if not founded */
int schr(char *s, char delim)
{
    int i, idx = -1;
    for (i = 0; *(s + i) != '\0'; i++)
        if (*(s + i) == delim)
            return idx = i;
    return idx;
}

/* Check on valid symbols */
int sspn(char str[], char sym[]) 
{
    int i;
    for( i = 0; str[i] != '\0' ; i++) {
        if( schr(sym, str[i] ) < 0 ) {
        return i = -1;
        }
    }
    return i;
}

/* Check on invalid smbols */
int scspn(char str[], char nsym[])
{
    int i;
    for (i = 0; str[i] != '\0' ; i++) {
        if (schr(nsym, *(str + i) ) >= 0 ) {
            return i;
        }
    }
    return i = -1;
}

/*Char to int*/
int atoi_str(char *str)
{
	int i, v = 0;

	for (i = 0; str[i] != '\0'; i++) {
		v = (10 * v) + (str[i] - '0');
	}
	return v;
}
