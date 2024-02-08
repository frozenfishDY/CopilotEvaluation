/**https://leetcode.com/problems/minimum-cost-to-split-an-array/ */
//You are given an integer array nums and an integer k.
//Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.
//Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.
//For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].
//The importance value of a subarray is k + trimmed(subarray).length.
//For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.
//Return the minimum possible cost of a split of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.


int minCost(int* nums, int numsSize, int k){
    int i, j, t, f;
    char *s = (char *)malloc(sizeof(char) * (n + 1));
    int *a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        f = 1;
        for (j = 1; j <= n - i - 1; j++) {
            f *= j;
        }
        t = (k - 1) / f;
        s[i] = a[t] + '0';
        for (j = t; j < n - i - 1; j++) {
            a[j] = a[j + 1];
        }
        k -= t * f;
    }
    s[n] = '\0';
    return s;

}

    