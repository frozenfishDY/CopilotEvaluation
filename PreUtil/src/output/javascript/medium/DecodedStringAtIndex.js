/**https://leetcode.com/problems/decoded-string-at-index/ */
//You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
//If the character read is a letter, that letter is written onto the tape.
//If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
//Given an integer k, return the kth letter (1-indexed) in the decoded string.


/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var decodeAtIndex = function(s, k) {
    let n = s.length;
    let size = 0;
    for(let i = 0; i < n; i++){
        if(!isNaN(s[i])){
            size *= s[i];
        }else{
            size++;
        }
    }
    for(let i = n - 1; i >= 0; i--){
        k %= size;
        if(k == 0 && isNaN(s[i])){
            return s[i];
        }
        if(!isNaN(s[i])){
            size /= s[i];
        }else{
            size--;
        }
    }
    return "";
    
};

    