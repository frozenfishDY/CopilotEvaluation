/**https://leetcode.com/problems/n-ary-tree-preorder-traversal/ */
//Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
//Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * 100);
    int index = 0;
    struct Node *p = root;
    struct Node *pre = NULL;
    while(p != NULL){
        if(p->numChildren == 0){
            result[index++] = p->val;
            p = p->children[0];
        }else{
            pre = p->children[p->numChildren - 1];
            while(pre->numChildren != 0 && pre->children[pre->numChildren - 1] != p){
                pre = pre->children[pre->numChildren - 1];
            }
            if(pre->numChildren == 0){
                pre->children[pre->numChildren++] = p;
                result[index++] = p->val;
                p = p->children[0];
            }else{
                pre->numChildren--;
                p = p->children[0];
            }
        }
    }
    *returnSize = index;
    return result;
    
}

    