/**https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/ */
//You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.
//For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
//Given the string word, return the minimum total distance to type such string using only two fingers.
//The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.
//Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.


/**
 * @param {string} word
 * @return {number}
 */
var minimumDistance = function(word) {
    let n = word.length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(26);
        for(let j = 0; j < dp[i].length; j++){
            dp[i][j] = new Array(26).fill(0);
        }
    }
    let dis = new Array(26);
    for(let i = 0; i < dis.length; i++){
        dis[i] = new Array(26).fill(0);
    }
    for(let i = 0; i < 26; i++){
        for(let j = 0; j < 26; j++){
            dis[i][j] = Math.floor(i / 6) - Math.floor(j / 6) + Math.abs(i % 6 - j % 6);
        }
    }
    for(let i = 0; i < n; i++){
        let cur = word.charCodeAt(i) - 65;
        for(let j = 0; j < 26; j++){
            for(let k = 0; k < 26; k++){
                if(i == 0){
                    dp[i][j][k] = dis[j][cur];
                }else{
                    dp[i][j][k] = Math.min(dp[i - 1][j][cur], dp[i - 1][k][cur]) + dis[k][cur];
                }
            }
        }
    }
    let ans = Number.MAX_VALUE;
    for(let i = 0; i < 26; i++){
        for(let j = 0; j < 26; j++){
            ans = Math.min(ans, dp[n - 1][i][j]);
        }
    }
    return ans;
    
    
};

    