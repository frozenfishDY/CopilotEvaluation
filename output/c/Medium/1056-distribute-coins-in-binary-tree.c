/**https://leetcode.com/problems/distribute-coins-in-binary-tree/ */
//You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.
//In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.
//Return the minimum number of moves required to make every node have exactly one coin.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int distributeCoins(struct TreeNode* root){
    int result = 0;
    distributeCoinsHelper(root, &result);
    return result;

}

    