/**https://leetcode.com/problems/count-of-range-sum/ */
//Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.


int countRangeSum(int* nums, int numsSize, int lower, int upper){
    int count = 0;
    long long sum = 0;
    int* queue = (int*)malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        while(head < tail && sum - queue[head] > upper) head++;
        while(head < tail && sum - queue[tail - 1] < lower) tail--;
        count += tail - head;
        queue[tail++] = sum;
    }
    return count;

}

    