/**https://leetcode.com/problems/longest-happy-prefix/ */
//A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
//Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.


/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
    let n = s.length;
    let lps = new Array(n).fill(0);
    let i = 1;
    let j = 0;
    while(i < n){
        if(s[i] == s[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return s.substring(0, lps[n - 1]);

    
};

    