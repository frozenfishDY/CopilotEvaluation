/**https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/ */
//You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
//Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and nums1[j] = nums1[j] - k.
//nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
//Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.


long long minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size, int k){
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i = 0; i < nums1Size; i++){
        sum1 += nums1[i];
    }
    for(int i = 0; i < nums2Size; i++){
        sum2 += nums2[i];
    }
    if(sum1 == sum2){
        return 0;
    }
    if(sum1 > sum2){
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
        long long tempSum = sum1;
        sum1 = sum2;
        sum2 = tempSum;
    }
    long long diff = sum2 - sum1;
    if(diff > k * 5){
        return -1;
    }
    int* nums1Count = (int*)malloc(sizeof(int) * 6);
    int* nums2Count = (int*)malloc(sizeof(int) * 6);
    for(int i = 0; i < 6; i++){
        nums1Count[i] = 0;
        nums2Count[i] = 0;
    }
    for(int i = 0; i < nums1Size; i++){
        nums1Count[nums1[i] - 1]++;
    }
    for(int i = 0; i < nums2Size; i++){
        nums2Count[nums2[i] - 1]++;
    }
    int* nums1CountSum = (int*)malloc(sizeof(int) * 6);
    int* nums2CountSum = (int*)malloc(sizeof(int) * 6);
    nums1CountSum[0] = nums1Count[0];
    nums2CountSum[0] = nums2Count[0];
    for(int i = 1; i < 6; i++){
        nums1CountSum[i] = nums1CountSum[i - 1] + nums1Count[i];
        nums2CountSum[i] = nums2CountSum[i - 1] + nums2Count[i];
    }
    int* nums1CountSumReverse = (int*)malloc(sizeof(int) * 6);
    int* nums2CountSumReverse = (int*)malloc(sizeof(int) * 6);

}

    