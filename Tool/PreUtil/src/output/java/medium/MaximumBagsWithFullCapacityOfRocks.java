/**https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/ */
//You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
//Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.


class MaximumBagsWithFullCapacityOfRocks {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int[] count = new int[100000];
        for (int i = 0; i < capacity.length; i++) {
            count[capacity[i]]++;
            count[rocks[i]]--;
        }
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        int result = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) {
                result += Math.min(additionalRocks, count[i]);
            }
        }
        return result;
        
    }
}
     
    