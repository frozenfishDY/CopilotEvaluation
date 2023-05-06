/**https://leetcode.com/problems/binary-trees-with-factors/ */
//Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
//We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
//Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.


/**
 * @param {number[]} arr
 * @return {number}
 */
var numFactoredBinaryTrees = function(arr) {
    let n = arr.length;
    let mod = 1000000007;
    let dp = new Array(n).fill(0);
    let map = new Map();
    arr.sort((a, b) => a - b);
    for(let i = 0; i < n; i++){
        dp[i] = 1;
        map.set(arr[i], i);
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < i; j++){
            if(arr[i] % arr[j] == 0){
                let right = arr[i] / arr[j];
                if(map.has(right)){
                    dp[i] = (dp[i] + (dp[j] * dp[map.get(right)]) % mod) % mod;
                }
            }
        }
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        result = (result + dp[i]) % mod;
    }
    return result;
    
};

    