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
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    int cnt = 0;
    while(cur) {
        cnt++;
        cur = cur->next;
    }
    if (cnt == 0) {
        return 0;
    }
    int arr[5000];
    cur = head;
    int i = 0;
    while(cur) {
        arr[cnt - i - 1] = cur->val;
        i++;
        cur = cur->next;
    }
    struct ListNode* headOfResult = 0;
    struct ListNode* prev = 0;
    cur = 0;
    for(int i = 0; i < cnt; i++) {
        cur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
        cur->val = arr[i];
        cur->next = 0;
        if (headOfResult == 0) {
            headOfResult = cur;
        }
        if (prev) {
            prev->next = cur;
        }
        prev = cur;
        cur = cur->next;
    }    
    return headOfResult;
}


void doTest(struct ListNode* head) {
    struct ListNode* headOfResult = reverseList(head);
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
        do {
            int N1 = 5;
            list1 = (struct ListNode*)malloc(sizeof(struct ListNode) * N1);
            struct ListNode* cur = list1;
            struct ListNode* it = list1;
            cur->val = 1;
            cur->next = ++it;
            cur = it;
            cur->val = 2;
            cur->next = ++it;
            cur = it;
            cur->val = 3;
            cur->next = ++it;
            cur = it;
            cur->val = 4;
            cur->next = ++it;
            cur = it;            
            cur->val = 5;
            cur->next = 0;    
        } while(0);

        doTest(list1);
        free(list1);            
    } while(0);

    do {
        struct ListNode* list1;        
        do {
            int N1 = 5;
            list1 = (struct ListNode*)malloc(sizeof(struct ListNode) * N1);
            struct ListNode* cur = list1;
            struct ListNode* it = list1;
            cur->val = 1;
            cur->next = ++it;
            cur = it;                     
            cur->val = 2;
            cur->next = 0;    
        } while(0);

        doTest(list1);
        free(list1);            
    } while(0);

    do {
        struct ListNode* list1 = 0;
        doTest(list1);
    } while(0);

    return 0;
}