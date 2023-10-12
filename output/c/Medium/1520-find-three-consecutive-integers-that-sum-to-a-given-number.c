/**https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/ */
//Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.
// 
//Example 1:
//Input: num = 33
//Output: [10,11,12]
//Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
//10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
//Example 2:
//Input: num = 4
//Output: []
//Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
// 
//Constraints:
//	0 <= num <= 1015
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* sumOfThree(long long num, int* returnSize){
long long* ret = malloc(sizeof(long long)*3);
    long long i;
    long long j;
    long long k;
    long long count;
    long long left;
    long long right;
    long long prev;
    long long next;
    long long* arr = malloc(sizeof(long long)*100000);
    i=0;
    while(i<100000){
        arr[i++]=0;
    }
    i=0;
    while(i<100000){
        arr[i++]=i;
    }
    i=0;
    while(i<100000){
        left=i-1;
        right=i+1;
        if(left<0){
            left=0;
        }
        if(right>100000){
            right=100000;
        }
        prev=arr[left];
        next=arr[right];
        if(prev+arr[i]+next==num){
            ret[0]=prev;
            ret[1]=arr[i];
            ret[2]=next;
            break;
        }
        i++;
    }
    *returnSize=3;
    return ret;
}