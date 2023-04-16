/**https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/ */
//A sequence x1, x2, ..., xn is Fibonacci-like if:
//n >= 3
//xi + xi+1 == xi+2 for all i + 2 <= n
//Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
//A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


int lenLongestFibSubseq(int* arr, int arrSize){
    int result = 0;
    int dp[arrSize][arrSize];
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < arrSize; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 2; i < arrSize; i++){
        int left = 0;
        int right = i - 1;
        while(left < right){
            if(arr[left] + arr[right] == arr[i]){
                dp[right][i] = dp[left][right] + 1;
                result = result > dp[right][i] ? result : dp[right][i];
                left++;
                right--;
            }else if(arr[left] + arr[right] < arr[i]){
                left++;
            }else{
                right--;
            }
        }
    }
    return result == 0 ? 0 : result + 2;

}

    