/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.


int shortestSubarray(int* nums, int numsSize, int k){
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

    