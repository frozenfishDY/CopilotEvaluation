/**https://leetcode.com/problems/substring-with-largest-variance/ */
//The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
//Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
//A substring is a contiguous sequence of characters within a string.


/**
 * @param {string} s
 * @return {number}
 */
var largestVariance = function(s) {
    let n = s.length;
    let ans = 0;
    for(let i = 0; i < n; i++){
        let count = new Array(26).fill(0);
        for(let j = i; j < n; j++){
            count[s[j].charCodeAt(0) - 'a'.charCodeAt(0)]++;
            let maxCount = 0;
            let minCount = n;
            for(let k = 0; k < 26; k++){
                if(count[k] > 0){
                    maxCount = Math.max(maxCount, count[k]);
                    minCount = Math.min(minCount, count[k]);
                }
            }
            ans = Math.max(ans, maxCount - minCount);
        }
    }
    return ans;
    
};

    