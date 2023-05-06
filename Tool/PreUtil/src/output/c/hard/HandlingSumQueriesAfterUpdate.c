/**https://leetcode.com/problems/handling-sum-queries-after-update/ */
//You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
//For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
//For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
//For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
//Return an array containing all the answers to the third type queries.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* handleQuery(int* nums1, int nums1Size, int* nums2, int nums2Size, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    long long* result = (long long*)malloc(sizeof(long long) * queriesSize);
    int* queue = (int*)malloc(sizeof(int) * nums1Size);
    int head = 0, tail = 0;
    for(int i = 0; i < nums1Size; i++){
        while(head < tail && nums1[queue[tail - 1]] < nums1[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result[i - k + 1] = nums1[queue[head]];
    }
    *returnSize = nums1Size - k + 1;
    return result;

}

    