/**https://leetcode.com/problems/find-right-interval/ */
//You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
//The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
//Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * intervalsSize);
    *returnSize = intervalsSize;
    for(int i = 0; i < intervalsSize; i++){
        int minIndex = -1;
        int minStart = INT_MAX;
        for(int j = 0; j < intervalsSize; j++){
            if(i != j && intervals[j][0] >= intervals[i][1] && intervals[j][0] < minStart){
                minStart = intervals[j][0];
                minIndex = j;
            }
        }
        result[i] = minIndex;
    }
    return result;

}

    