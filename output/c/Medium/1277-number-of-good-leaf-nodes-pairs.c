/**https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/ */
//You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//Return the number of good leaf node pairs in the tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countPairs(struct TreeNode* root, int distance){
    int count = 0;
    int* arr = (int*)malloc(sizeof(int) * distance);
    for(int i = 0; i < distance; i++){
        arr[i] = 0;
    }
    countPairsHelper(root, distance, arr, &count);
    return count;

}

    