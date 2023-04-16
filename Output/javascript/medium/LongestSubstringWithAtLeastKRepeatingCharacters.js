/**https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ */
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubstring = function(s, k) {
    let n = s.length;
    let result = 0;
    for(let i = 0; i <= n - k; i++){
        let map = new Map();
        let max = 0;
        let min = n;
        for(let j = i; j < n; j++){
            if(map.has(s[j])){
                map.set(s[j], map.get(s[j]) + 1);
            }else{
                map.set(s[j], 1);
            }
            if(map.get(s[j]) > max){
                max = map.get(s[j]);
            }
            if(map.get(s[j]) < min){
                min = map.get(s[j]);
            }
            if(max - min >= k){
                result = Math.max(result, j - i + 1);
            }
        }
    }
    return result;
    
};

    