/**https://leetcode.com/problems/linked-list-components/ */
//You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
//Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int numComponents(struct ListNode* head, int* nums, int numsSize){
    int* hash = (int*)malloc(sizeof(int) * 10000);
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        hash[nums[i]] = 1;
    }
    while(head != NULL){
        if(hash[head->val] == 1 && (head->next == NULL || hash[head->next->val] == 0)){
            count++;
        }
        head = head->next;
    }
    return count;

}

    