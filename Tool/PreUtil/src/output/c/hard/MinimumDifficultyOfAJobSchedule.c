/**https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/ */
//You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
//You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.
//You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
//Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.


int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*jobDifficultySize);
    for(i=0;i<jobDifficultySize;i++){
        arr[i] = 0;
    }
    int* dp = (int*)malloc(sizeof(int)*jobDifficultySize);
    for(i=0;i<jobDifficultySize;i++){
        dp[i] = 0;
    }
    for(i=0;i<d;i++){
        for(j=0;j<jobDifficultySize;j++){
            if(i==0){
                if(j==0){
                    dp[j] = jobDifficulty[j];
                }
                else{
                    dp[j] = dp[j-1]+jobDifficulty[j];
                }
            }
            else{
                if(j==0){
                    dp[j] = dp[j]+jobDifficulty[j];
                }
                else{
                    int max = jobDifficulty[j];
                    for(k=j-1;k>=0;k--){
                        if(max<jobDifficulty[k]){
                            max = jobDifficulty[k];
                        }
                        if(dp[k]+max<dp[j]){
                            dp[j] = dp[k]+max;
                        }
                    }
                }
            }
        }
    }
    return dp[jobDifficultySize-1];

}

    