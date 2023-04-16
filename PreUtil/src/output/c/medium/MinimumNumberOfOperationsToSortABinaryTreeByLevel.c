/**https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/ */
//You are given the root of a binary tree with unique values.
//In one operation, you can choose any two nodes at the same level and swap their values.
//Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
//The level of a node is the number of edges along the path between it and the root node.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minimumOperations(struct TreeNode* root){
    int i, j, k, n = 0, *arr = malloc(10000 * sizeof(int));
    struct TreeNode *temp = root;
    while(temp != NULL){
        arr[n++] = temp->val;
        temp = temp->left;
    }
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    struct TreeNode* newNode(int val){
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    struct TreeNode* build(int l, int r){
        if(l > r){
            return NULL;
        }
        int mid = (l + r) / 2;
        struct TreeNode* root = newNode(arr[mid]);
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }
    return build(0, n - 1);

}

    