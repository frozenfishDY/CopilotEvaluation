/**https://leetcode.com/problems/balance-a-binary-search-tree/ */
//Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
//A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* balanceBST(struct TreeNode* root){
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

    