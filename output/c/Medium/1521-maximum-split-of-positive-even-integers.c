/**https://leetcode.com/problems/maximum-split-of-positive-even-integers/ */
//You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.
//	For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
//Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.
// 
//Example 1:
//Input: finalSum = 12
//Output: [2,4,6]
//Explanation: The following are valid splits: (12), (2 + 10), (2 + 4 + 6), and (4 + 8).
//(2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we return [2,4,6].
//Note that [2,6,4], [6,2,4], etc. are also accepted.
//Example 2:
//Input: finalSum = 7
//Output: []
//Explanation: There are no valid splits for the given finalSum.
//Thus, we return an empty array.
//Example 3:
//Input: finalSum = 28
//Output: [6,8,2,12]
//Explanation: The following are valid splits: (2 + 26), (6 + 8 + 2 + 12), and (4 + 24). 
//(6 + 8 + 2 + 12) has the maximum number of integers, which is 4. Thus, we return [6,8,2,12].
//Note that [10,2,4,12], [6,2,4,16], etc. are also accepted.
// 
//Constraints:
//	1 <= finalSum <= 1010
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* maximumEvenSplit(long long finalSum, int* returnSize){
long long* ret = malloc(sizeof(long long)*finalSum);
    long long i;
    long long j;
    long long k;
    long long count;
    long long left;
    long long right;
    long long prev;
    long long next;
    long long* arr = malloc(sizeof(long long)*finalSum);
    i=0;
    while(i<finalSum){
        arr[i++]=0;
    }
    i=0;
    while(i<finalSum){
        arr[i++]=finalSum;
    }
    i=0;
    while(i<finalSum){
        left=i-time;
        right=i+time;
        if(left<0){
            left=0;
        }
        if(right>finalSum){
            right=finalSum;
        }
        count=0;
        for(j=left;j<=right;j++){
            if(arr[j]==1){
                count++;
            }
        }
        if(count==time*2+1){
            for(j=left;j<=right;j++){
                arr[j]=0;
            }
        }
        i++;
    }
    i=0;
    count=0;
    while(i<finalSum){
        if(arr[i]>0){
            count++;
        }
        i++;
    }
    *returnSize=count;
    i=0;
    count=0;
    while(i<finalSum){
        if(arr[i]>0){
            ret[count++]=arr[i];
        }
        i++;
    }
    return ret;
}