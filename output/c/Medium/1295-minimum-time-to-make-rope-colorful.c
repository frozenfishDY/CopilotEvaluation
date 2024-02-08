/**https://leetcode.com/problems/minimum-time-to-make-rope-colorful/ */
//Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
//Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
//Return the minimum time Bob needs to make the rope colorful.


int minCost(char * colors, int* neededTime, int neededTimeSize){
    int i, j, k, len = strlen(colors), min = 0, count = 0;
    int dp[26][len];
    for(i = 0; i < 26; i++){
        for(j = 0; j < len; j++){
            dp[i][j] = 0;
        }
    }
    for(i = 0; i < len; i++){
        dp[colors[i] - 'a'][i] = neededTime[i];
    }
    for(i = 0; i < 26; i++){
        for(j = 1; j < len; j++){
            if(dp[i][j] != 0){
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    for(i = 0; i < len; i++){
        min = 0;
        for(j = 0; j < 26; j++){
            if(dp[j][i] != 0){
                if(min == 0){
                    min = dp[j][i];
                }else if(min > dp[j][i]){
                    min = dp[j][i];
                }
            }
        }
        count += min;
    }
    return count;

}

    