/**https://leetcode.com/problems/decode-xored-permutation/ */
//There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.
//It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].
//Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.


/**
 * @param {number[]} encoded
 * @return {number[]}
 */
var decode = function(encoded) {
    let n = encoded.length + 1;
    let total = 0;
    for(let i = 1; i <= n; i++){
        total ^= i;
    }
    let odd = 0;
    for(let i = 1; i < n - 1; i += 2){
        odd ^= encoded[i];
    }
    let perm = new Array(n);
    perm[0] = total ^ odd;
    for(let i = 0; i < n - 1; i++){
        perm[i+1] = perm[i] ^ encoded[i];
    }
    return perm;
    
};

    