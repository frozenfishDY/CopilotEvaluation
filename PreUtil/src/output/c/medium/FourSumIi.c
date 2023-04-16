/**https://leetcode.com/problems/4sum-ii/ */
//Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
//0 <= i, j, k, l < n
//nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0


int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    int* nums1Count = (int*)malloc(sizeof(int) * 2001);
    int* nums2Count = (int*)malloc(sizeof(int) * 2001);
    int* nums3Count = (int*)malloc(sizeof(int) * 2001);
    int* nums4Count = (int*)malloc(sizeof(int) * 2001);
    for(int i = 0; i < 2001; i++){
        nums1Count[i] = 0;
        nums2Count[i] = 0;
        nums3Count[i] = 0;
        nums4Count[i] = 0;
    }
    for(int i = 0; i < nums1Size; i++){
        nums1Count[nums1[i] + 1000]++;
        nums2Count[nums2[i] + 1000]++;
        nums3Count[nums3[i] + 1000]++;
        nums4Count[nums4[i] + 1000]++;
    }
    int* nums1CountSum = (int*)malloc(sizeof(int) * 2001);
    int* nums2CountSum = (int*)malloc(sizeof(int) * 2001);
    int* nums3CountSum = (int*)malloc(sizeof(int) * 2001);
    int* nums4CountSum = (int*)malloc(sizeof(int) * 2001);
    nums1CountSum[0] = nums1Count[0];
    nums2CountSum[0] = nums2Count[0];
    nums3CountSum[0] = nums3Count[0];
    nums4CountSum[0] = nums4Count[0];
    for(int i = 1; i < 2001; i++){
        nums1CountSum[i] = nums1CountSum[i - 1] + nums1Count[i];
        nums2CountSum[i] = nums2CountSum[i - 1] + nums2Count[i];
        nums3CountSum[i] = nums3CountSum[i - 1] + nums3Count[i];
        nums4CountSum[i] = nums4CountSum[i - 1] + nums4Count[i];
    }
    int* nums1CountSumReverse = (int*)malloc(sizeof(int) * 2001);
    int* nums2CountSumReverse = (int*)malloc(sizeof(int) * 2001 );

}

    