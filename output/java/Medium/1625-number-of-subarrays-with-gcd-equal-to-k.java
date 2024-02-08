/**https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The greatest common divisor of an array is the largest integer that evenly divides all the array elements.


class NumberOfSubarraysWithGcdEqualToK {
    public int subarrayGCD(int[] nums, int k) {
        int[] count = new int[k + 1];
        for(int i = 0; i < nums.length; i++){
            int gcd = nums[i];
            for(int j = i; j < nums.length; j++){
                gcd = gcd(gcd, nums[j]);
                if(gcd == k){
                    count[k]++;
                }else if(gcd < k){
                    count[gcd]++;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= k; i++){
            ans += count[i];
        }
        return ans;
        
        
    }
}
     
    