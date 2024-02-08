/**https://leetcode.com/problems/rank-transform-of-a-matrix/ */
//Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].
//The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:
//The rank is an integer starting from 1.
//If two elements p and q are in the same row or column, then:
//If p < q then rank(p) < rank(q)
//If p == q then rank(p) == rank(q)
//If p > q then rank(p) > rank(q)
//The rank should be as small as possible.
//The test cases are generated so that answer is unique under the given rules.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixRankTransform(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
      
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*matrixSize);
    for(i=0;i<matrixSize;i++){
        arr[i] = 0;
    }
    for(i=1;i<matrixSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<matrixSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return arr;

}

    