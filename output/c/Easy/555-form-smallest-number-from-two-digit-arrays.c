/**https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/ */
//Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.
// 
//Example 1:
//Input: nums1 = [4,1,3], nums2 = [5,7]
//Output: 15
//Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
//Example 2:
//Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
//Output: 3
//Explanation: The number 3 contains the digit 3 which exists in both arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 9
//	1 <= nums1[i], nums2[i] <= 9
//	All digits in each array are unique.
int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int *c = (int*)calloc(10, sizeof(int));
    int *d = (int*)calloc(10, sizeof(int));
    for (i = 0; i < nums1Size; i++) {
        c[nums1[i]]++;
    }
    for (i = 0; i < nums2Size; i++) {
        d[nums2[i]]++;
    }
    for (i = 0; i < 10; i++) {
        if (c[i] > 0 && d[i] > 0) {
            return i;
        }
    }
    return 0;
}