/**https://leetcode.com/problems/sum-of-subarray-minimums/ */
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


/**
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function(arr) {
    let n = arr.length;
    let stack = [];
    let left = new Array(n);
    let right = new Array(n);
    for(let i = 0; i < n; i++){
        while(stack.length > 0 && arr[stack[stack.length - 1]] > arr[i]){
            stack.pop();
        }
        if(stack.length == 0){
            left[i] = -1;
        }else{
            left[i] = stack[stack.length - 1];
        }
        stack.push(i);
    }
    stack = [];
    for(let i = n - 1; i >= 0; i--){
        while(stack.length > 0 && arr[stack[stack.length - 1]] >= arr[i]){
            stack.pop();
        }
        if(stack.length == 0){
            right[i] = n;
        }else{
            right[i] = stack[stack.length - 1];
        }
        stack.push(i);
    }
    let result = 0;
    let mod = Math.pow(10, 9) + 7;
    for(let i = 0; i < n; i++){
        result = (result + arr[i] * (i - left[i]) * (right[i] - i)) % mod;
    }
    return result;
    
};

    