/**https://leetcode.com/problems/new-21-game/ */
//Alice plays the following game, loosely based on the card game "21".
//Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
//Alice stops drawing numbers when she gets k or more points.
//Return the probability that Alice has n or fewer points.
//Answers within 10-5 of the actual answer are considered accepted.


double new21Game(int n, int k, int maxPts){
    if(k == 0 || n >= k + maxPts - 1){
        return 1;
    }
    double dp[k + maxPts];
    double sum = 1;
    for(int i = 1; i <= maxPts; i++){
        dp[i] = i <= n ? 1 : 0;
        sum += dp[i];
    }
    for(int i = maxPts + 1; i <= k + maxPts - 1; i++){
        dp[i] = sum / maxPts;
        sum += dp[i] - dp[i - maxPts];
    }
    for(int i = k; i <= n; i++){
        dp[i] = sum / maxPts;
        sum -= dp[i];
    }
    return dp[n];

}

    