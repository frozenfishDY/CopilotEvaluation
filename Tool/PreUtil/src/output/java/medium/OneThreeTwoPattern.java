/**https://leetcode.com/problems/132-pattern/ */
//Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//Return true if there is a 132 pattern in nums, otherwise, return false.


class OneThreeTwoPattern {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] min = new int[n];
        min[0] = nums[0];
        for(int i = 1; i < n; i++){
            min[i] = Math.min(min[i - 1], nums[i]);
        }
        Stack<Integer> stack = new Stack<>();
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > min[i]){
                while(!stack.isEmpty() && stack.peek() <= min[i]){
                    stack.pop();
                }
                if(!stack.isEmpty() && stack.peek() < nums[i]){
                    return true;
                }
                stack.push(nums[i]);
            }
        }
        return false;
        
        
    }
}

    