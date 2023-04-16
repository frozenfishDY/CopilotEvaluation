/**https://leetcode.com/problems/longest-consecutive-sequence/ */
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.


class LongestConsecutiveSequence {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int num : nums){
            set.add(num);
        }
        int max = 0;
        for(int num : nums){
            if(!set.contains(num - 1)){
                int cur = num;
                int count = 1;
                while(set.contains(cur + 1)){
                    cur++;
                    count++;
                }
                max = Math.max(max, count);
            }
        }
        return max;
        
    }
}

    