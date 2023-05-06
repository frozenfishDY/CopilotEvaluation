/**https://leetcode.com/problems/merge-k-sorted-lists/ */
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int i = 0;
    int minIndex = -1;
    int minVal = 0;
    int flag = 0;
    while(1){
        minIndex = -1;
        minVal = 0;
        flag = 0;
        for(i = 0; i < listsSize; i++){
            if(lists[i] != NULL){
                if(flag == 0){
                    minIndex = i;
                    minVal = lists[i]->val;
                    flag = 1;
                }else{
                    if(lists[i]->val < minVal){
                        minIndex = i;
                        minVal = lists[i]->val;
                    }
                }
            }
        }
        if(minIndex == -1){
            break;
        }
        if(head == NULL){
            head = lists[minIndex];
            tail = head;
        }else{
            tail->next = lists[minIndex];
            tail = tail->next;
        }
        lists[minIndex] = lists[minIndex]->next;
    }
    return head;

}

    