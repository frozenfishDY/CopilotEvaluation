/**https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/ */
//A sequence x1, x2, ..., xn is Fibonacci-like if:
//n >= 3
//xi + xi+1 == xi+2 for all i + 2 <= n
//Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
//A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


/**
 * @param {number[]} arr
 * @return {number}
 */
var lenLongestFibSubseq = function(arr) {
    let n = arr.length;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n).fill(0);
    }
    let result = 0;
    let map = new Map();
    for(let i = 0; i < n; i++){
        map.set(arr[i], i);
    }
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            let k = map.get(arr[j] - arr[i]);
            if(k !== undefined && k < i){
                dp[i][j] = dp[k][i] + 1;
                result = Math.max(result, dp[i][j]);
            }
        }
    }
    return result;
    
};

    