/**https://leetcode.com/problems/unique-binary-search-trees/ */
//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.


int numTrees(int n){
    int* result = (int*)malloc(sizeof(int) * (n + 1));
    result[0] = 1;
    result[1] = 1;
    for(int i = 2; i <= n; i++){
        result[i] = 0;
        for(int j = 0; j < i; j++){
            result[i] += result[j] * result[i - j - 1];
        }
    }
    return result[n];

}

    