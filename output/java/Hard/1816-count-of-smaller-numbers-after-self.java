/**https://leetcode.com/problems/count-of-smaller-numbers-after-self/ */
//Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].


class CountOfSmallerNumbersAfterSelf {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        int[] indexes = new int[n];
        for (int i = 0; i < n; i++) {
            indexes[i] = i;
        }
        int[] counts = new int[n];
        mergeSort(nums, indexes, counts, 0, n - 1);
        List<Integer> ans = new ArrayList<Integer>();
        for (int count : counts) {
            ans.add(count);
        }
        return ans;
        
        
    }
}
     
    