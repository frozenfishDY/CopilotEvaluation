/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.


class CountTheNumberOfGoodSubarrays {
    public long countGood(int[] nums, int k) {
        int n = nums.length;
        int[] odd = new int[n + 2];
        int m = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                odd[++m] = i;
            }
        }
        odd[0] = -1;
        odd[++m] = n;
        long res = 0;
        for(int i = k; i <= m - k; i++){
            res += (long)(odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
        }
        return res;
        
        
    }
}

    