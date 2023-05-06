/**https://leetcode.com/problems/minimize-deviation-in-array/ */
//You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//If the element is even, divide it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//If the element is odd, multiply it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeviation = function(nums) {
    let n = nums.length;
    let pq = new PriorityQueue((a, b) => a - b);
    let max = 0;
    for(let i = 0; i < n; i++){
        if(nums[i] % 2 == 1){
            nums[i] *= 2;
        }
        pq.add(nums[i]);
        max = Math.max(max, nums[i]);
    }
    let res = Infinity;
    while(pq.size() > 0){
        let cur = pq.poll();
        res = Math.min(res, max - cur);
        if(cur % 2 == 0){
            cur /= 2;
            max = Math.max(max, cur);
            pq.add(cur);
        }else{
            break;
        }
    }
    return res;
    
    
};

    