/**https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ */
//Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.
//Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
//If no such second minimum value exists, output -1 instead.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root){
    if(root == NULL){
        return -1;
    }
    int left = root->left->val;
    int right = root->right->val;
    if(left == root->val){
        left = findSecondMinimumValue(root->left);
    }
    if(right == root->val){
        right = findSecondMinimumValue(root->right);
    }
    if(left != -1 && right != -1){
        return left < right ? left : right;
    }
    if(left != -1){
        return left;
    }
    return right;

}

    