#include <stdio.h>

bool isSubsequence(char* s, char* t) {
    int lenS = 0;
    char* curS = s;
    
    while(*curS != '\0') {
        lenS++;
        curS++;
    }

    int countOfFound = 0;
    char* curT = t;
    for (int i = 0; i < lenS; i++) {          
        if(*curT == '\0') {
            return false;
        }
        char toFound = s[i];
        bool flagFound = false;
        while(*curT != '\0') {
            if (*curT == toFound) {
                curT++;
                flagFound = true;
                countOfFound++;
                break;
            }
            curT++;
        }
        if (!flagFound) {                        
            return false;
        }
    }
    if (countOfFound == lenS) {
        return true;
    } else {
        return false;
    }
}

void doTest(char* s, char* t) {
    bool result = isSubsequence(s, t);
    printf("(%s) (%s) (%d)\n", s, t, result);
}

int main() {
    do {
        char s[] = "abc";
        char t[] = "ahbgdc";
        doTest(s, t);
    } while(0);

    do {
        char s[] = "axc";
        char t[] = "ahbgdc";
        doTest(s, t);
    } while(0);

    do {
        char s[] = "aaa";
        char t[] = "bba";
        doTest(s, t);
    } while(0);

    do {
        char s[] = "aaaaaa";
        char t[] = "bbaaaa";
        doTest(s, t);
    } while(0);

    return 0;
}