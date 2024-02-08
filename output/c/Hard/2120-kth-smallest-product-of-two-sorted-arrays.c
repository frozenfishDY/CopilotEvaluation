/**https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/ */
//Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.


long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2, int nums2Size, long long k){
    long long i,j,k;
    long long* arr = (long long*)malloc(sizeof(long long)*nums1Size);
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

    