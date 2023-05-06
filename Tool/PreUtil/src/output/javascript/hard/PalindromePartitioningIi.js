/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.


/**
 * @param {string} s
 * @return {number}
 */
var minCut = function(s) {
    let n = s.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push(0);
        }
    }
    let cuts = [];
    for(let i = 0; i < n; i++){
        cuts.push(i);
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j <= i; j++){
            if(s[i] === s[j] && (i - j < 2 || dp[j + 1][i - 1])){
                dp[j][i] = true;
                if(j === 0){
                    cuts[i] = 0;
                }else{
                    cuts[i] = Math.min(cuts[i], cuts[j - 1] + 1);
                }
            }
        }
    }
    return cuts[n - 1];
    
};

    