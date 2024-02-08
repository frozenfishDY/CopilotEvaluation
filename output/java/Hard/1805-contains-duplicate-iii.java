/**https://leetcode.com/problems/contains-duplicate-iii/ */
//You are given an integer array nums and two integers indexDiff and valueDiff.
//Find a pair of indices (i, j) such that:
//i != j,
//abs(i - j) <= indexDiff.
//abs(nums[i] - nums[j]) <= valueDiff, and
//Return true if such pair exists or false otherwise.


class ContainsDuplicateIii {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        int n = nums.length;
        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            Long ceiling = set.ceiling((long) nums[i] - valueDiff);
            if (ceiling != null && ceiling <= (long) nums[i] + valueDiff) {
                return true;
            }
            set.add((long) nums[i]);
            if (i >= indexDiff) {
                set.remove((long) nums[i - indexDiff]);
            }
        }
        return false;
        
    }
}
     
    