#include <stdio.h>
#include <string.h>

int romanToInt(char * s) {
    int total = 0;
    char* cur = s;
    char lastChar;
    while(*cur != '\0') {
        int val;
        if(*cur == 'I') {            
            val = 1;
        } else if (*cur == 'V') {
            if (lastChar == 'I') {
                val = 4 - 1;
            } else {
                val = 5;
            }
        } else if (*cur == 'X') {
            if (lastChar == 'I') {
                val = 9 - 1;
            } else {
                val = 10;
            }            
        } else if (*cur == 'L') {
            if (lastChar == 'X') {
                val = 40 - 10;
            } else {
                val = 50;
            }
        } else if (*cur == 'C') {
            if (lastChar == 'X') {
                val = 90 - 10;
            } else {
                val = 100;
            }
        } else if (*cur == 'D') {
            if (lastChar == 'C') {
                val = 400 - 100;
            } else {
                val = 500;
            }
        } else if (*cur == 'M') {
            if (lastChar == 'C') {
                val = 900 - 100;
            } else {
                val = 1000;
            }
        } else {
            val = 0;
        }
        total += val;
        lastChar = *cur;
        cur++;
    }
    return total;
}

void doTest(char* p) {
    int total = romanToInt(p);
    printf("(%s)(%d)\n", p, total);
}

int main() {
    char t1[1024];
    strcpy(t1, "III");
    doTest(t1);
    strcpy(t1, "LVIII");
    doTest(t1);
    strcpy(t1, "MCMXCIV");
    doTest(t1);
    return 0;
}