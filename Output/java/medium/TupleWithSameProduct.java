/**https://leetcode.com/problems/tuple-with-same-product/ */
//Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.


class TupleWithSameProduct {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                map.put(nums[i] * nums[j], map.getOrDefault(nums[i] * nums[j], 0) + 1);
            }
        }
        for(int key : map.keySet()){
            int count = map.get(key);
            res += count * (count - 1) * 4;
        }
        return res;
        
    }
}
     
    