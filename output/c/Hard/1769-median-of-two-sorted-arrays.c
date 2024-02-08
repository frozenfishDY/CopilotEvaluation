/**https://leetcode.com/problems/median-of-two-sorted-arrays/ */
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = 0, j = 0, k = 0;
    int *arr = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j]){
            arr[k++] = nums1[i++];
        }else{
            arr[k++] = nums2[j++];
        }
    }
    while(i < nums1Size){
        arr[k++] = nums1[i++];
    }
    while(j < nums2Size){
        arr[k++] = nums2[j++];
    }
    if((nums1Size + nums2Size) % 2 == 0){
        return (arr[(nums1Size + nums2Size) / 2] + arr[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
    }else{
        return arr[(nums1Size + nums2Size) / 2];
    }

}

    