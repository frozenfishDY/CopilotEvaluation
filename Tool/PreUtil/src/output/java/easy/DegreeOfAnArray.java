/**https://leetcode.com/problems/degree-of-an-array/ */
//Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.


class DegreeOfAnArray {
    public int findShortestSubArray(int[] nums) {
        int max = 0;
        int min = Integer.MAX_VALUE;
        int[] count = new int[50000];
        int[] first = new int[50000];
        for(int i = 0; i < nums.length; i++){
            if(count[nums[i]] == 0){
                first[nums[i]] = i;
            }
            count[nums[i]]++;
            max = Math.max(max, count[nums[i]]);
        }
        for(int i = 0; i < nums.length; i++){
            if(count[nums[i]] == max){
                min = Math.min(min, i - first[nums[i]] + 1);
            }
        }
        return min;
        
        
    }
}

    