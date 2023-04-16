/**https://leetcode.com/problems/next-greater-node-in-linked-list/ */
//You are given the head of a linked list with n nodes.
//For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
//Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 10000);
    int* stack = (int*)malloc(sizeof(int) * 10000);
    int top = -1;
    int i = 0;
    while(head != NULL){
        while(top != -1 && result[stack[top]] < head->val){
            result[stack[top]] = head->val;
            top--;
        }
        stack[++top] = i;
        result[i++] = 0;
        head = head->next;
    }
    *returnSize = i;
    return result;

}

    