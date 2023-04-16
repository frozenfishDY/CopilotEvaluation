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


int racecar(int target){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int* dp = (int*)malloc(sizeof(int) * (target + 1));
    for(i = 0; i <= target; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(i = 1; i <= target; i++){
        int k = 1;
        int pos = 1;
        while(pos < i){
            for(j = 0; j < k; j++){
                dp[i] = fmin(dp[i], dp[i - pos] + k + 1);
            }
            k++;
            pos = (1 << k) - 1;
        }
        if(pos == i){
            dp[i] = k;
        }else{
            for(j = 0; j < k - 1; j++){
                dp[i] = fmin(dp[i], dp[pos - i] + k + j);
            }
        }
    }
    return dp[target];

}

    