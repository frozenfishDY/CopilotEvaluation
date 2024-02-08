/**https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/ */
//We run a preorder depth-first search (DFS) on the root of a binary tree.
//At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
//If a node has only one child, that child is guaranteed to be the left child.
//Given the output traversal of this traversal, recover the tree and return its root.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recoverFromPreorder(char * traversal){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr[i] = 0;
    }
    int count = 0;
    int temp = 0;
    for(i=0;i<strlen(traversal);i++){
        if(traversal[i]=='-'){
            arr[count] = temp;
            temp = 0;
            count++;
        }
        else{
            temp = temp*10 + (traversal[i]-'0');
        }
    }
    arr[count] = temp;
    count++;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;
    struct TreeNode* temp2 = root;
    for(i=1;i<count;i++){
        struct TreeNode* temp3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp3->val = arr[i];
        temp3->left = NULL;
        temp3->right = NULL;
        if(arr[i-1]<arr[i]){
            temp2->left = temp3;
            temp2 = temp3;
        }
        else{
            while(arr[i-1]!=arr[i]){
                temp2 = temp2->left;
                i--;
            }
            temp2->right = temp3;
            temp2 = temp3;
        }
    }
    return root;

}

    