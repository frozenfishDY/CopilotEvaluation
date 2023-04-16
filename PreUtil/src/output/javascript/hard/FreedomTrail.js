/**https://leetcode.com/problems/freedom-trail/ */
//In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.
//Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.
//Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.
//At the stage of rotating the ring to spell the key character key[i]:
//You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
//If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.


/**
 * @param {string} ring
 * @param {string} key
 * @return {number}
 */
var findRotateSteps = function(ring, key) {
    let m = ring.length;
    let n = key.length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i < m; i++){
        dp[i][n] = 0;
    }
    for(let j = n - 1; j >= 0; j--){
        for(let i = 0; i < m; i++){
            dp[i][j] = Number.MAX_VALUE;
            for(let k = 0; k < m; k++){
                if(ring[k] === key[j]){
                    let diff = Math.abs(i - k);
                    let step = Math.min(diff, m - diff);
                    dp[i][j] = Math.min(dp[i][j], step + dp[k][j + 1]);
                }
            }
        }
    }
    return dp[0][0] + n;
    
    
};

    