/**https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */
//You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* arr[100];
    int i = 0;
    struct ListNode* temp = head;
    while(temp != NULL){
        arr[i] = temp;
        temp = temp->next;
        i++;
    }
    int tempVal = arr[k - 1]->val;
    arr[k - 1]->val = arr[i - k]->val;
    arr[i - k]->val = tempVal;
    return head;

}

    