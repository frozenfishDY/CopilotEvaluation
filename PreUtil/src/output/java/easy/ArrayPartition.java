/**https://leetcode.com/problems/array-partition/ */
//Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.


class ArrayPartition {
    public int arrayPairSum(int[] nums) {
        int[] count = new int[20001];
        for(int i = 0; i < nums.length; i++){
            count[nums[i] + 10000]++;
        }
        int sum = 0;
        boolean flag = true;
        for(int i = 0; i < count.length; i++){
            while(count[i] > 0){
                if(flag){
                    sum += i - 10000;
                }
                flag = !flag;
                count[i]--;
            }
        }
        return sum;
        
        
    }
}

    