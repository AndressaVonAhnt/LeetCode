#include <stdio.h>
#include <stdlib.h>

struct ListNode{
     int val;
     struct ListNode *next;
} ;

void printList(struct ListNode* head) {
    struct ListNode* current = head;  // Start from the head of the list
    while (current != NULL) {          // Loop until we reach the end of the list
        printf("%d ", current->val); // Print the value of the current node
        current = current->next;       // Move to the next node
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *current1 = list1;
    struct ListNode *current2 = list2;
    struct ListNode *current = malloc(sizeof(struct ListNode));
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head = current;
    current->next = NULL;

    if(current1 == NULL && current2 == NULL)
        return NULL;
    
        
    while(current1 != NULL || current2 != NULL){
        current->next = malloc(sizeof(struct ListNode));
        current->next->next = NULL;

        if(current1 != NULL)
            if(current2 != NULL)
                if(current1->val < current2->val){
                    current->val = current1->val;
                    current1 = current1->next;
                }  

                else{
                    current->val = current2->val;
                    current2 = current2->next;
                }  

            else{
                current->val = current1->val;
                current1 = current1->next;
            }

        else{
            current->val = current2->val;
            current2 = current2->next;
        }

        if(current1 != NULL || current2 != NULL)
            current = current->next;
        else
            current->next = NULL;
    }

    return head;
}

int main(){
    struct ListNode* list1 = malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    struct ListNode* list2 = malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    printList(mergeTwoLists(list1, list2));
    return 0;
}