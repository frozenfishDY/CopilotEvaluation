/**https://leetcode.com/problems/max-dot-product-of-two-subsequences/ */
//Given two arrays nums1 and nums2.
//Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
//A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).


int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i,j,k;
    int** arr = (int**)malloc(sizeof(int*)*nums1Size);
    for(i=0;i<nums1Size;i++){
        arr[i] = (int*)malloc(sizeof(int)*nums2Size);
    }
    for(i=0;i<nums1Size;i++){
        for(j=0;j<nums2Size;j++){
            arr[i][j] = nums1[i] * nums2[j];
        }
    }
    for(i=1;i<nums1Size;i++){
        for(j=1;j<nums2Size;j++){
            int max = 0;
            for(k=1;k<=i && k<=j;k++){
                if(arr[i-k][j-k]>max){
                    max = arr[i-k][j-k];
                }
            }
            arr[i][j] = arr[i][j] + max;
        }
    }
    int max = 0;
    for(i=0;i<nums1Size;i++){
        for(j=0;j<nums2Size;j++){
            if(arr[i][j]>max){
                max = arr[i][j];
            }
        }
    }
    return max;

}

    