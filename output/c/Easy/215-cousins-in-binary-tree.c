/**https://leetcode.com/problems/cousins-in-binary-tree/ */
//Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
//Two nodes of a binary tree are cousins if they have the same depth with different parents.
//Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
// 
//Example 1:
//Input: root = [1,2,3,4], x = 4, y = 3
//Output: false
//Example 2:
//Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
//Output: true
//Example 3:
//Input: root = [1,2,3,null,4], x = 2, y = 3
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 100].
//	1 <= Node.val <= 100
//	Each node has a unique value.
//	x != y
//	x and y are exist in the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCousins(struct TreeNode* root, int x, int y){
int depth[101];
    int parent[101];
    memset(depth,0,sizeof(depth));
    memset(parent,0,sizeof(parent));
    int top=0;
    struct TreeNode* stack[101];
    stack[top++]=root;
    int i;
    while(top>0){
        struct TreeNode* node=stack[--top];
        if(node->left!=NULL){
            depth[node->left->val]=depth[node->val]+1;
            parent[node->left->val]=node->val;
            stack[top++]=node->left;
        }
        if(node->right!=NULL){
            depth[node->right->val]=depth[node->val]+1;
            parent[node->right->val]=node->val;
            stack[top++]=node->right;
        }
    }
    if(depth[x]!=depth[y]){
        return false;
    }
    if(parent[x]==parent[y]){
        return false;
    }
    return true;
}