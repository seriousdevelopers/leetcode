#include <iostream>
#include <stdio.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int values[16];
        int index = 0;
        while(true) {            
            values[index++] = x % 10;
            x = x / 10;
            if (x == 0) {
                break;
            }
        }
        if (index == 1) {
            return true;
        }        
        for (int i = 0; i < index / 2; i++) {
            if (values[i] != values[index - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

void doTest(Solution* sol, int input) {
    bool r = sol->isPalindrome(input);
    std::cout << input << "/r: " << r << std::endl;
}

int main() {
    Solution* sol = new Solution();
    doTest(sol, 1);
    doTest(sol, 121);
    doTest(sol, 1221);
    doTest(sol, 12221);
    doTest(sol, 123);
    doTest(sol, 1233);
    doTest(sol, 12321);
    doTest(sol, 12331);
    doTest(sol, -121);    
    delete sol;
    return 0;
}