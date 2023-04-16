/**https://leetcode.com/problems/k-radius-subarray-averages/ */
//You are given a 0-indexed array nums of n integers, and an integer k.
//The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.
//Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.
//The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.
//For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.


class KRadiusSubarrayAverages {
    public int[] getAverages(int[] nums, int k) {
        int n = nums.length;
        int[] res = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(i <= k){
                sum += nums[i];
                if(i == k){
                    res[i - k] = sum / (k + 1);
                }
            }else{
                sum += nums[i];
                sum -= nums[i - k - 1];
                res[i - k] = sum / (k + 1);
            }
        }
        for(int i = n - k; i < n; i++){
            sum -= nums[i - k - 1];
            res[i] = sum / (n - i + k);
        }
        return res;
        
    }
}
     
    