/**https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/ */
//You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
//You are allowed to choose exactly one element from each row to form an array.
//Return the kth smallest array sum among all possible arrays.


int kthSmallest(int** mat, int matSize, int* matColSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*matSize);
    for(i=0;i<matSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<matSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<matSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;


}

    