/**https://leetcode.com/problems/construct-target-array-with-multiple-sums/ */
//You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
//let x be the sum of all elements currently in your array.
//choose index i, such that 0 <= i < n and set the value of arr at index i to x.
//You may repeat this procedure as many times as needed.
//Return true if it is possible to construct the target array from arr, otherwise, return false.


/**
 * @param {number[]} target
 * @return {boolean}
 */
var isPossible = function(target) {
    let sum = 0;
    let max = 0;
    let maxIndex = 0;
    for(let i = 0; i < target.length; i++){
        sum += target[i];
        if(target[i] > max){
            max = target[i];
            maxIndex = i;
        }
    }
    if(sum == target.length) return true;
    if(sum < target.length) return false;
    while(sum > target.length){
        let prevMax = max;
        sum -= max;
        if(sum == 1) return true;
        max = max - sum;
        if(max <= 0 || max == prevMax) return false;
        sum += max;
    }
    return true;
    
};

    