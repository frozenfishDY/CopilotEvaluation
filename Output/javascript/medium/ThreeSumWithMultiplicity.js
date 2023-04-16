/**https://leetcode.com/problems/3sum-with-multiplicity/ */
//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 10^9 + 7.


/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var threeSumMulti = function(arr, target) {
    let n = arr.length;
    let mod = 1000000007;
    let count = new Array(101).fill(0);
    for(let i = 0; i < n; i++){
        count[arr[i]]++;
    }
    let result = 0;
    for(let i = 0; i <= 100; i++){
        for(let j = i; j <= 100; j++){
            let k = target - i - j;
            if(k < 0 || k > 100){
                continue;
            }
            if(i == j && j == k){
                result += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
            }else if(i == j && j != k){
                result += count[i] * (count[i] - 1) / 2 * count[k];
            }else if(i < j && j < k){
                result += count[i] * count[j] * count[k];
            }
        }
    }
    return result % mod;
    
};

    