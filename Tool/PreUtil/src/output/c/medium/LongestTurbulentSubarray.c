/**https://leetcode.com/problems/longest-turbulent-subarray/ */
//Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
//A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
//More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
//For i <= k < j:
//arr[k] > arr[k + 1] when k is odd, and
//arr[k] < arr[k + 1] when k is even.
//Or, for i <= k < j:
//arr[k] > arr[k + 1] when k is even, and
//arr[k] < arr[k + 1] when k is odd.


int maxTurbulenceSize(int* arr, int arrSize){
    int* dp = (int*)malloc(sizeof(int) * arrSize);
    dp[0] = 1;
    int max = 1;
    for(int i = 1; i < arrSize; i++){
        if(arr[i] == arr[i - 1]){
            dp[i] = 1;
        }else if(i == 1 || (arr[i] > arr[i - 1] && arr[i - 1] < arr[i - 2]) || (arr[i] < arr[i - 1] && arr[i - 1] > arr[i - 2])){
            dp[i] = dp[i - 1] + 1;
        }else{
            dp[i] = 2;
        }
        max = fmax(max, dp[i]);
    }
    return max;

}

    