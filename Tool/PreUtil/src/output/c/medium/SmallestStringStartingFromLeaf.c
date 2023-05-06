/**https://leetcode.com/problems/smallest-string-starting-from-leaf/ */
//You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
//Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
//As a reminder, any shorter prefix of a string is lexicographically smaller.
//For example, "ab" is lexicographically smaller than "aba".
//A leaf of a node is a node that has no children.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char * smallestFromLeaf(struct TreeNode* root){
    char* result = (char*)malloc(sizeof(char) * 1000);
    result[0] = '\0';
    smallestFromLeafHelper(root, result);
    return result;


}

    