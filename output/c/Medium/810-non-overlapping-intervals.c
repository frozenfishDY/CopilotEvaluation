/**https://leetcode.com/problems/non-overlapping-intervals/ */
//Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize == 0){
        return 0;
    }
    int* dp = (int*)malloc(sizeof(int) * intervalsSize);
    for(int i = 0; i < intervalsSize; i++){
        dp[i] = 1;
    }
    int max = 1;
    for(int i = 1; i < intervalsSize; i++){
        for(int j = 0; j < i; j++){
            if(intervals[i][0] >= intervals[j][1]){
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        max = fmax(max, dp[i]);
    }
    return intervalsSize - max;

}

    