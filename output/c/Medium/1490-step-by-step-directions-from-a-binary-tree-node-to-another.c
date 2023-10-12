/**https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/ */
//You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
//Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
//	'L' means to go from a node to its left child node.
//	'R' means to go from a node to its right child node.
//	'U' means to go from a node to its parent node.
//Return the step-by-step directions of the shortest path from node s to node t.
// 
//Example 1:
//Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
//Output: "UURL"
//Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
//Example 2:
//Input: root = [2,1], startValue = 2, destValue = 1
//Output: "L"
//Explanation: The shortest path is: 2 → 1.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= n
//	All the values in the tree are unique.
//	1 <= startValue, destValue <= n
//	startValue != destValue
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char * getDirections(struct TreeNode* root, int startValue, int destValue){
int* arr = malloc(sizeof(int)*1000);
    char* ret = malloc(sizeof(char)*1000);
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    int temp1 = 0;
    int temp2 = 0;
    int count = 0;
    struct TreeNode* node = root;
    while(node){
        arr[i]=node->val;
        i++;
        if(node->val==startValue){
            temp1=i;
        }
        if(node->val==destValue){
            temp2=i;
        }
        node=node->left;
    }
    for(j=0;j<i;j++){
        if(arr[j]==startValue){
            temp=j;
            break;
        }
    }
    for(j=temp;j<i;j++){
        if(arr[j]==destValue){
            break;
        }
        if(arr[j]>arr[j+1]){
            ret[k]='L';
            k++;
        }else{
            ret[k]='R';
            k++;
        }
    }
    if(temp1<temp2){
        count=temp2-temp1;
    }else{
        count=temp1-temp2;
    }
    for(j=0;j<count;j++){
        ret[k]='U';
        k++;
    }
    ret[k]='\0';
    return ret;
}