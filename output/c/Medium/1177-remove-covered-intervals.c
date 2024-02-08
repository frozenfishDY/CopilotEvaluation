/**https://leetcode.com/problems/remove-covered-intervals/ */
//Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
//The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
//Return the number of remaining intervals.


int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int count = 0;
    for(int i = 0; i < intervalsSize; i++){
        int isCovered = 0;
        for(int j = 0; j < intervalsSize; j++){
            if(i == j){
                continue;
            }
            if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                isCovered = 1;
                break;
            }
        }
        if(!isCovered){
            count++;
        }
    }
    return count;

}

    