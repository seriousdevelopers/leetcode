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
struct ListNode* middleNode(struct ListNode* head) {
    int cnt = 0;
    struct ListNode* cur = head;
    while(cur) {
        cur = cur->next;
        cnt++;
    }    
    int index = 0;
    cur = head;
    while(cur) {        
        if (index >= cnt / 2) {
            break;
        }
        cur = cur->next;
        index++;
    }
    return cur;
}

void printList(struct ListNode* head) {
    printf("[");
    ListNode* cur = head;
    while(cur) {
        printf(" %d ", cur->val);
        cur = cur->next;     
    }
    printf("]");
    printf("\n");
}

void buildList(struct ListNode** ppHead, int* values, int n) {
    ListNode* head = 0;
    ListNode* prevNode;
    for (int i = 0; i < n; i++) {
        ListNode* newNode = (ListNode*)(malloc(sizeof(ListNode) * 1));
        newNode->val = values[i];
        newNode->next = 0;
        if (i == 0) {
            head = newNode;
        } else {
            prevNode->next = newNode;
        }
        prevNode = newNode;
    }
    *ppHead = head;
}

void cleanUpList(struct ListNode** ppHead, int n) {
    ListNode* cur = *ppHead;
    for (int i = 0; i < n; i++) {
        ListNode* next = cur->next;            
        free(cur);
        cur = next;
    }
}

void testAll() {
    do {
        int N = 5;
        int values[] = {1, 2, 3, 4, 5};
        struct ListNode* head = 0;
        buildList(&head, values, N);     

        // This one prints input.
        printList(head);

        // This one gets the main result.
        ListNode* resultNode = middleNode(head);

        // This one prints output.
        if(resultNode) {
            printList(resultNode);
        }

        // Now clean up.
        cleanUpList(&head, N);
    } while(0);

    do {
        int N = 6;
        int values[] = {1, 2, 3, 4, 5, 6};
        struct ListNode* head = 0;
        buildList(&head, values, N);     

        // This one prints input.
        printList(head);

        // This one gets the main result.
        ListNode* resultNode = middleNode(head);

        // This one prints output.
        if(resultNode) {
            printList(resultNode);
        }

        // Now clean up.
        cleanUpList(&head, N);
    } while(0);
}

int main() {
    testAll();
    return 0;
}