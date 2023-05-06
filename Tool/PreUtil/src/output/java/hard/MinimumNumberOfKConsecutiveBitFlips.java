/**https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/ */
//You are given a binary array nums and an integer k.
//A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
//Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
//A subarray is a contiguous part of an array.


class MinimumNumberOfKConsecutiveBitFlips {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int[] diff = new int[n+1];
        int res = 0;
        int revCnt = 0;
        for(int i=0;i<n;i++){
            revCnt += diff[i];
            if((nums[i]+revCnt)%2==0){
                if(i+k>n) return -1;
                res++;
                revCnt++;
                diff[i+k]--;
            }
        }
        return res;
        
    }
}
     
    