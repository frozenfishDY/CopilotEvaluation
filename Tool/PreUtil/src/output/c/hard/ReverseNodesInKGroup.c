/**https://leetcode.com/problems/reverse-nodes-in-k-group/ */
//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be changed.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *p = head;
    struct ListNode *q = NULL;
    struct ListNode *r = NULL;
    struct ListNode *s = NULL;
    struct ListNode *t = NULL;
    struct ListNode *u = NULL;
    int i = 0;
    int j = 0;
    int flag = 0;
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    if(len < k){
        return head;
    }
    p = head;
    q = head;
    r = head;
    s = head;
    t = head;
    u = head;
    for(i = 0; i < len / k; i++){
        for(j = 0; j < k - 1; j++){
            q = q->next;
        }
        r = q->next;
        q->next = NULL;
        s = p;
        t = p->next;
        while(t != NULL){
            u = t->next;
            t->next = s;
            s = t;
            t = u;
        }
        if(flag == 0){
            head = s;
            flag = 1;
        }else{
            p->next = s;
        }
        p = r;
        q = r;
    }
    p->next = r;
    return head;

}

    