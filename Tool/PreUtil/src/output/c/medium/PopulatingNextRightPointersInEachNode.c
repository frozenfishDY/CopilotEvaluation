/**https://leetcode.com/problems/populating-next-right-pointers-in-each-node/ */
//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if(root == NULL){
        return NULL;
    }
    struct Node* temp = root;
    while(temp->left != NULL){
        struct Node* temp1 = temp;
        while(temp1 != NULL){
            temp1->left->next = temp1->right;
            if(temp1->next != NULL){
                temp1->right->next = temp1->next->left;
            }
            temp1 = temp1->next;
        }
        temp = temp->left;
    }
    return root;
	
}

    