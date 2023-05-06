/**https://leetcode.com/problems/flip-string-to-monotone-increasing/ */
//A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
//You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
//Return the minimum number of flips to make s monotone increasing.


/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function(s) {
    let n = s.length;
    let result = 0;
    let ones = 0;
    for(let i = 0; i < n; i++){
        if(s[i] == '1'){
            ones++;
        }else{
            result = Math.min(result + 1, ones);
        }
    }
    return result;
    
};

    