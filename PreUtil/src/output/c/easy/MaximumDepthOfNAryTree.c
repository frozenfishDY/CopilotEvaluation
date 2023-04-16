/**https://leetcode.com/problems/maximum-depth-of-n-ary-tree/ */
//Given a n-ary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) {
    if(root == NULL){
        return 0;
    }
    int max = 0;
    for(int i = 0; i < root->numChildren; i++){
        int depth = maxDepth(root->children[i]);
        if(depth > max){
            max = depth;
        }
    }
    return max + 1;
    
}

    