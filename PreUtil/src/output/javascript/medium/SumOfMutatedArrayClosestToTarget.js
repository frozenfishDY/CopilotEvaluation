/**https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/ */
//Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
//In case of a tie, return the minimum such integer.
//Notice that the answer is not neccesarilly a number from arr.


/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var findBestValue = function(arr, target) {
    let n = arr.length;
    let l = 0;
    let r = 0;
    for(let i = 0; i < n; i++){
        r = Math.max(r, arr[i]);
    }
    while(l <= r){
        let mid = Math.floor((l + r) / 2);
        let sum = 0;
        for(let i = 0; i < n; i++){
            sum += Math.min(arr[i], mid);
        }
        if(sum < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    let sum1 = 0;
    let sum2 = 0;
    for(let i = 0; i < n; i++){
        sum1 += Math.min(arr[i], l);
        sum2 += Math.min(arr[i], l - 1);
    }
    return Math.abs(sum1 - target) <= Math.abs(sum2 - target) ? l : l - 1;
    
};

    