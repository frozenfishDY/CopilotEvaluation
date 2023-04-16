/**https://leetcode.com/problems/race-car/ */
//Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
//When you get an instruction 'A', your car does the following:
//position += speed
//speed *= 2
//When you get an instruction 'R', your car does the following:
//If your speed is positive then speed = -1
//otherwise speed = 1
//Your position stays the same.
//For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.
//Given a target position target, return the length of the shortest sequence of instructions to get there.


/**
 * @param {number} target
 * @return {number}
 */
var racecar = function(target) {
    let dp = new Array(target + 1).fill(0);
    for(let i = 1; i <= target; i++){
        dp[i] = Number.MAX_SAFE_INTEGER;
        let k = 1;
        let pos = 1;
        while(pos < i){
            for(let j = 0; j < k; j++){
                dp[i] = Math.min(dp[i], dp[i - pos] + k + 1 + j);
            }
            k++;
            pos = Math.pow(2, k) - 1;
        }
        if(pos === i){
            dp[i] = Math.min(dp[i], k);
        }
        else{
            for(let j = 0; j < k; j++){
                dp[i] = Math.min(dp[i], dp[pos - i] + k + 1 + j);
            }
        }
    }
    return dp[target];
    
};

    