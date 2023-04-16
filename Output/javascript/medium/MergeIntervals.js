/**https://leetcode.com/problems/merge-intervals/ */
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    let result = [];
    if(intervals.length == 0){
        return result;
    }
    intervals.sort((a, b) => a[0] - b[0]);
    let current = intervals[0];
    for(let i = 1; i < intervals.length; i++){
        if(intervals[i][0] <= current[1]){
            current[1] = Math.max(current[1], intervals[i][1]);
        } else {
            result.push(current);
            current = intervals[i];
        }
    }
    result.push(current);
    return result;
};

    