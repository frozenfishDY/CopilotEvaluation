/**https://leetcode.com/problems/maximum-length-of-repeated-subarray/ */
//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.


int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int** dp = (int**)malloc(sizeof(int*) * (nums1Size + 1));
    for(int i = 0; i <= nums1Size; i++){
        dp[i] = (int*)malloc(sizeof(int) * (nums2Size + 1));
        for(int j = 0; j <= nums2Size; j++){
            dp[i][j] = 0;
        }
    }
    int result = 0;
    for(int i = 1; i <= nums1Size; i++){
        for(int j = 1; j <= nums2Size; j++){
            if(nums1[i - 1] == nums2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = result > dp[i][j] ? result : dp[i][j];
            }
        }
    }
    return result;

}

    