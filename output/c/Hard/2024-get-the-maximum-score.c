/**https://leetcode.com/problems/get-the-maximum-score/ */
//You are given two sorted arrays of distinct integers nums1 and nums2.
//A valid path is defined as follows:
//Choose array nums1 or nums2 to traverse (from index-0).
//Traverse the current array from left to right.
//If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
//The score is defined as the sum of uniques values in a valid path.
//Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 10^9 + 7.


int maxSum(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*nums1

}

    