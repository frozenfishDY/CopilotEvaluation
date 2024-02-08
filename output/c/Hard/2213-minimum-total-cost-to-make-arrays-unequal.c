/**https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/ */
//You are given two 0-indexed integer arrays nums1 and nums2, of equal length n.
//In one operation, you can swap the values of any two indices of nums1. The cost of this operation is the sum of the indices.
//Find the minimum total cost of performing the given operation any number of times such that nums1[i] != nums2[i] for all 0 <= i <= n - 1 after performing all the operations.
//Return the minimum total cost such that nums1 and nums2 satisfy the above condition. In case it is not possible, return -1.


long long minimumTotalCost(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<nums1Size;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[nums1Size-1];


}

    