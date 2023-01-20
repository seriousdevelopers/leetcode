#include <stdio.h>

typedef struct {
    char source;
    char destination;
} TUPLE;

bool isIsomorphic(char * s, char * t) {
    char* p1 = s;
    char* p2 = t;
    
    char map0[256] = {0, };
    char map1[256] = {0, };

    bool flagUnmatchedTupleFound = false;

    while(*p1 != '\0') {
        if (map0[*p1] == '\0') {
            if (map1[*p2] != '\0') {
                flagUnmatchedTupleFound = true;
                break;
            }
            map0[*p1] = *p2;
            map1[*p2] = *p1;
            continue;
        } else if (map1[*p2] == '\0') {            
            flagUnmatchedTupleFound = true;
            break;
        }
        if (map0[*p1] != *p2 || map1[*p2] != *p1) {
            flagUnmatchedTupleFound = true;
            break;
        }
        map0[*p1] = *p2;
        map1[*p2] = *p1;

        p1++;
        p2++;
    }

    return !flagUnmatchedTupleFound;
}

void doTest(char* s, char* t) {
    bool result = isIsomorphic(s, t);
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int main() {

    do {
        char s[256] = "egg";
        char t[256] = "add";
        doTest(s, t);
    } while (0);

    do {
        char s[256] = "foo";
        char t[256] = "bar";
        doTest(s, t);
    } while (0);

    do {
        char s[256] = "paper";
        char t[256] = "title";
        doTest(s, t);
    } while (0);

    return 0;
}