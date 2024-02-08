/**https://leetcode.com/problems/merge-bsts-to-create-single-bst/ */
//You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:
//Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
//Replace the leaf node in trees[i] with trees[j].
//Remove trees[j] from trees.
//Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.
//A BST (binary search tree) is a binary tree where each node satisfies the following property:
//Every node in the node's left subtree has a value strictly less than the node's value.
//Every node in the node's right subtree has a value strictly greater than the node's value.
//A leaf is a node that has no children.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* canMerge(struct TreeNode** trees, int treesSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*treesSize);
    for(i=0;i<treesSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<treesSize;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[treesSize-1];


}

    