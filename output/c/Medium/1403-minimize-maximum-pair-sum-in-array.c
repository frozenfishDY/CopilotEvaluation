/**https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/ */
//The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs._x000D_
//_x000D_
//_x000D_
//	For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8._x000D_
//_x000D_
//_x000D_
//Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:_x000D_
//_x000D_
//_x000D_
//	Each element of nums is in exactly one pair, and_x000D_
//	The maximum pair sum is minimized._x000D_
//_x000D_
//_x000D_
//Return the minimized maximum pair sum after optimally pairing up the elements._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [3,5,2,3]_x000D_
//Output: 7_x000D_
//Explanation: The elements can be paired up into pairs (3,3) and (5,2)._x000D_
//The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [3,5,4,2,4,6]_x000D_
//Output: 8_x000D_
//Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2)._x000D_
//The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	n == nums.length_x000D_
//	2 <= n <= 105_x000D_
//	n is even._x000D_
//	1 <= nums[i] <= 105_x000D_


int minPairSum(int* nums, int numsSize){
int i;
    int max=0;
    int min=0;
    int mid;
    int sum;
    int max_sum=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]>max){
            max=nums[i];
        }
    }
    max_sum=2*max;
    while(min<=max){
        mid=(min+max)/2;
        sum=0;
        for(i=0;i<numsSize/2;i++){
            if(nums[i]+nums[numsSize-1-i]>mid){
                sum+=nums[i]+nums[numsSize-1-i];
            }else{
                sum+=mid;
            }
        }
        if(sum>max_sum){
            min=mid+1;
        }else{
            max=mid-1;
        }
    }
    return min;
}