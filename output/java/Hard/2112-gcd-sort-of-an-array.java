/**https://leetcode.com/problems/gcd-sort-of-an-array/ */
//You are given an integer array nums, and you can perform the following operation any number of times on nums:
//Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
//Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.


class GcdSortOfAnArray {
    public boolean gcdSort(int[] nums) {
        int n = nums.length;
        int[] pre = new int[n + 1];
        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + (nums[i] < k ? -1 : 1);
        }
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i <= n; i++){
            res += map.getOrDefault(pre[i], 0);
            map.put(pre[i] + 1, map.getOrDefault(pre[i] + 1, 0) + 1);
        }
        return res;
        
    }
}
     
    