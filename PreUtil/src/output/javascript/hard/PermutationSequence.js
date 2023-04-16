/**https://leetcode.com/problems/permutation-sequence/ */
//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.


/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    let arr = [];
    let result = "";
    for(let i = 1; i <= n; i++){
        arr.push(i);
    }
    let fact = 1;
    for(let i = 1; i <= n; i++){
        fact = fact * i;
    }
    k = k - 1;
    for(let i = 0; i < n; i++){
        fact = fact / (n - i);
        let index = Math.floor(k / fact);
        result = result + arr[index];
        arr.splice(index, 1);
        k = k % fact;
    }
    return result;
    
};

    