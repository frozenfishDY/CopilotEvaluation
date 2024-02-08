/**https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/ */
//Given a binary tree
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
    while(temp != NULL){
        struct Node* temp1 = temp;
        struct Node* temp2 = NULL;
        while(temp1 != NULL){
            if(temp1->left != NULL){
                if(temp2 == NULL){
                    temp2 = temp1->left;
                }
                else{
                    temp2->next = temp1->left;
                    temp2 = temp2->next;
                }
            }
            if(temp1->right != NULL){
                if(temp2 == NULL){
                    temp2 = temp1->right;
                }
                else{
                    temp2->next = temp1->right;
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
        temp = temp2;
    }
    return root;
	
}

    