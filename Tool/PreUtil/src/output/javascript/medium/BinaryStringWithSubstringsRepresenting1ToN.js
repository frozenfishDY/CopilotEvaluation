/**https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/ */
//Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
//A substring is a contiguous sequence of characters within a string.


/**
 * @param {string} s
 * @param {number} n
 * @return {boolean}
 */
var queryString = function(s, n) {
    let set = new Set();
    let i = 0;
    let j = 0;
    while(i < s.length){
        let num = 0;
        j = i;
        while(j < s.length){
            num = num * 2 + (s[j] - '0');
            if(num > n){
                break;
            }
            set.add(num);
            j++;
        }
        i++;
    }
    for(let i = 1; i <= n; i++){
        if(!set.has(i)){
            return false;
        }
    }
    return true;
    
};

    