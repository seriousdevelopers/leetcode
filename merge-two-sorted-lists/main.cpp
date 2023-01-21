#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;   
    struct ListNode* cur = 0;
    struct ListNode* prev = 0;
    struct ListNode* headOfResult = 0;
    
    while(true) {        
        if (p1 == 0 && p2 == 0) {
            break;
        }
        if (p1 == 0) {
            // Take an element from list2.            
            cur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);            
            if (prev) {
               prev->next = cur;
            }
            if (headOfResult == 0) {
                headOfResult = cur;
            }
            prev = cur;
            cur->val = p2->val;
            p2 = p2->next;
        } else if (p2 == 0) {
            // Take an element from list1.            
            cur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);            
            if (prev) {
               prev->next = cur;
            }
            if (headOfResult == 0) {
                headOfResult = cur;
            }
            prev = cur;
            cur->val = p1->val;            
            p1 = p1->next;
        } else {
            if (p1->val <= p2->val) {                
                cur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);            
                if (prev) {
                   prev->next = cur;
                }
                if (headOfResult == 0) {
                   headOfResult = cur;
                }
                prev = cur;
                cur->val = p1->val;                
                p1 = p1->next;
            } else {                           
                cur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);            
                if (prev) {
                   prev->next = cur;
                }
                if (headOfResult == 0) {
                   headOfResult = cur;
                }
                prev = cur;
                cur->val = p2->val;                
                p2 = p2->next;
            }
        }
    }
    if(cur) {
        cur->next = 0;
    }

    return headOfResult;
}

void doTest(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* headOfResult = mergeTwoLists(list1, list2);
    struct ListNode* cur = headOfResult;
    printf("[ ");
    while(cur) {
        printf("%d ", cur->val);
        cur = cur->next; 
    }
    printf("]\n");
}

int main() {
    do {
        struct ListNode* list1;
        struct ListNode* list2;
        do {
            int N1 = 3;
            list1 = (struct ListNode*)malloc(sizeof(struct ListNode) * N1);
            struct ListNode* cur = list1;
            struct ListNode* it = list1;
            cur->val = 1;
            cur->next = ++it;
            cur = it;
            cur->val = 2;
            cur->next = ++it;
            cur = it;
            cur->val = 4;
            cur->next = 0;    
        } while(0);

        do {
            int N2 = 3;
            list2 = (struct ListNode*)malloc(sizeof(struct ListNode) * N2);
            struct ListNode* cur = list2;
            struct ListNode* it = list2;
            cur->val = 1;
            cur->next = ++it;
            cur = it;
            cur->val = 3;
            cur->next = ++it;
            cur = it;
            cur->val = 4;
            cur->next = 0;
        } while(0);
        doTest(list1, list2);
        free(list1);
        free(list2);    
    } while(0);

    do {
        struct ListNode* list1 = 0;
        struct ListNode* list2 = 0;    
        doTest(list1, list2);        
    } while(0);

    do {
        struct ListNode* list1 = 0;
        struct ListNode* list2;    
        do {
            int N2 = 1;
            list2 = (struct ListNode*)malloc(sizeof(struct ListNode) * N2);
            struct ListNode* cur = list2;
            struct ListNode* it = list2;
            cur->val = 0;
            cur->next = 0;            
        } while(0);
        doTest(list1, list2);        
        free(list2);            
    } while(0);

    do {
        struct ListNode* list1 = 0;
        struct ListNode* list2;    
        do {
            int N2 = 1;
            list2 = (struct ListNode*)malloc(sizeof(struct ListNode) * N2);
            struct ListNode* cur = list2;
            struct ListNode* it = list2;
            cur->val = 1;
            cur->next = 0;            
        } while(0);
        doTest(list1, list2);        
        free(list2);            
    } while(0);

    return 0;
}