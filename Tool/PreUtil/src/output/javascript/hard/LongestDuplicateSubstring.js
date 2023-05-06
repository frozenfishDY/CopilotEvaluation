/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".


/**
 * @param {string} s
 * @return {string}
 */
var longestDupSubstring = function(s) {
    let n = s.length;
    let a = 26;
    let mod = 2**32;
    let left = 1;
    let right = n;
    let ans = '';
    while(left <= right){
        let mid = Math.floor((left + right) / 2);
        let found = rabinKarp(s, mid, a, mod);
        if(found != -1){
            ans = s.substring(found, found + mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
    
    
};

    