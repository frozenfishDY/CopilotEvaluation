/**https://leetcode.com/problems/minimize-deviation-in-array/ */
//You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//If the element is even, divide it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//If the element is odd, multiply it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.


class MinimizeDeviationInArray {
    public int minimumDeviation(int[] nums) {
        int n = nums.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                nums[i] *= 2;
            }
            pq.add(nums[i]);
            min = Math.min(min, nums[i]);
        }
        int res = Integer.MAX_VALUE;
        while(!pq.isEmpty()){
            int cur = pq.poll();
            res = Math.min(res, cur - min);
            if(cur % 2 == 0){
                cur /= 2;
                min = Math.min(min, cur);
                pq.add(cur);
            }else{
                break;
            }
        }
        return res;
        
    }
}
     
    