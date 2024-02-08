/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).


/**
 * @param {string} text
 * @return {number}
 */
var distinctEchoSubstrings = function(text) {
    let n = text.length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n).fill(0);
    }
    let ans = 0;
    let set = new Set();
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            if(text[i] == text[j]){
                if(i == 0 || j == n - 1){
                    dp[i][j] = 1;
                }else if(dp[i - 1][j + 1] == 1){
                    dp[i][j] = 1;
                }
            }
            if(dp[i][j] == 1){
                let str = text.substring(i, j + 1);
                if(!set.has(str)){
                    set.add(str);
                    ans++;
                }
            }
        }
    }
    return ans;
    
};

    