/**https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/ */
//Given 2n balls of k distinct colors. You will be given an integer array balls of size k where balls[i] is the number of balls of color i.
//All the balls will be shuffled uniformly at random, then we will distribute the first n balls to the first box and the remaining n balls to the other box (Please read the explanation of the second example carefully).
//Please note that the two boxes are considered different. For example, if we have two balls of colors a and b, and two boxes [] and (), then the distribution [a] (b) is considered different than the distribution [b] (a) (Please read the explanation of the first example carefully).
//Return the probability that the two boxes have the same number of distinct balls. Answers within 10-5 of the actual value will be accepted as correct.


/**
 * @param {number[]} balls
 * @return {number}
 */
var getProbability = function(balls) {
    let n = balls.length;
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += balls[i];
    }
    let dp = new Array(sum + 1).fill(0);
    dp[0] = 1;
    for(let i = 0; i < n; i++){
        for(let j = sum; j >= balls[i]; j--){
            dp[j] += dp[j - balls[i]];
        }
    }
    let total = dp[sum];
    let half = sum / 2;
    let ans = 0;
    for(let i = 0; i <= half; i++){
        ans += dp[i] * dp[sum - i];
    }
    return ans / total;
    
};

    