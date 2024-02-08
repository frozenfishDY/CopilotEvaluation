/**https://leetcode.com/problems/subsets/ */
//Given an integer array nums of unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.


class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length == 0){
            return res;
        }
        helper(nums, 0, new ArrayList<>(), res);
        return res;
        
        
        
    }
}

    