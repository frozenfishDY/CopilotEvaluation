/**https://leetcode.com/problems/maximum-equal-frequency/ */
//Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.
//If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).


class MaximumEqualFrequency {
    public int maxEqualFreq(int[] nums) {
        int[] count = new int[100001];
        int[] freq = new int[100001];
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int c = count[num];
            if (c > 0) {
                freq[c]--;
            }
            count[num]++;
            freq[count[num]]++;
            if (freq[c] == 0 && c == max) {
                max--;
            }
            if (freq[count[num]] == 1) {
                max = Math.max(max, count[num]);
            }
            if (freq[1] == i + 1 || (freq[max] * max == i && freq[max + 1] == 1) || (freq[1] == 1 && freq[max] * max == i)) {
                return i + 1;
            }
        }
        return nums.length;
        
    }
}
     
    