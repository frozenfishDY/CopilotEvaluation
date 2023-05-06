/**https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/ */
//You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
//For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
//Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
//An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].


int minSwap(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *a = (int *)malloc(sizeof(int) * nums1Size);
    int *b = (int *)malloc(sizeof(int) * nums1Size);
    int i, j, k, t, m = 0;
    for (i = 0; i < nums1Size; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    for (i = 1; i < nums1Size; i++) {
        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
            a[i] = a[i - 1];
            b[i] = b[i - 1] + 1;
        }
        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
            if (a[i - 1] + 1 < a[i]) {
                a[i] = a[i - 1] + 1;
                b[i] = b[i - 1];
            }
        }
    }
    return a[nums1Size - 1];

}

    