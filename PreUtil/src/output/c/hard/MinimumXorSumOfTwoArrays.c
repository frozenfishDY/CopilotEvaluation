/**https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/ */
//You are given two integer arrays nums1 and nums2 of length n.
//The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).
//For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
//Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
//Return the XOR sum after the rearrangement.


int minimumXORSum(int* nums1, int nums1Size, int* nums2, int nums2Size){
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

    