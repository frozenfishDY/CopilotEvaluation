/**https://leetcode.com/problems/non-overlapping-intervals/ */
//Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


/**
 * @param {number[][]} intervals
 * @return {number}
 */
var eraseOverlapIntervals = function(intervals) {
    let n = intervals.length;
    if(n == 0){
        return 0;
    }
    intervals.sort((a, b) => a[1] - b[1]);
    let count = 1;
    let end = intervals[0][1];
    for(let i = 1; i < n; i++){
        if(intervals[i][0] >= end){
            count++;
            end = intervals[i][1];
        }
    }
    return n - count;
    
};

    