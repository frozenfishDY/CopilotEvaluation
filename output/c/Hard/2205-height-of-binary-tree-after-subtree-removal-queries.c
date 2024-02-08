/**https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/ */
//You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
//You have to perform m independent queries on the tree where in the ith query you do the following:
//Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
//Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
//Note:
//The queries are independent, so the tree returns to its initial state after each query.
//The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*2);
    for(i=0;i<2;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=0;i<strlen(s);i++){
        if(s[i] == '0'){
            arr[0] = (arr[0] + arr[1])%1000000007;
        }
        else{
            arr[1] = (arr[0] + arr[1])%1000000007;
        }
    }
    return arr[0];

}

    