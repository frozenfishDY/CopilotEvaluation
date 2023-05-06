/**https://leetcode.com/problems/binary-trees-with-factors/ */
//Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
//We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
//Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.


int numFactoredBinaryTrees(int* arr, int arrSize){
    int* dp = (int*)malloc(sizeof(int) * arrSize);
    int* hash = (int*)malloc(sizeof(int) * 100000);
    int result = 0;
    int mod = 1000000007;
    for(int i = 0; i < arrSize; i++){
        dp[i] = 1;
        hash[arr[i]] = i;
    }
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] % arr[j] == 0){
                int index = hash[arr[i] / arr[j]];
                if(index != 0){
                    dp[i] = (dp[i] + dp[j] * dp[index]) % mod;
                }
            }
        }
        result = (result + dp[i]) % mod;
    }
    return result;

}

    