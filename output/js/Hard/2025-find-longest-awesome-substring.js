/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.


/**
 * @param {string} s
 * @return {number}
 */
var longestAwesome = function(s) {
    let n = s.length;
    let dp = new Array(1024).fill(-1);
    dp[0] = -1;
    let res = 0;
    let mask = 0;
    for(let i = 0; i < n; i++){
        let idx = s.charCodeAt(i) - 48;
        mask ^= (1 << idx);
        if(dp[mask] != -1){
            res = Math.max(res, i - dp[mask]);
        }else{
            dp[mask] = i;
        }
        for(let j = 0; j < 10; j++){
            let newMask = mask ^ (1 << j);
            if(dp[newMask] != -1){
                res = Math.max(res, i - dp[newMask]);
            }
        }
    }
    return res;
    
};

    