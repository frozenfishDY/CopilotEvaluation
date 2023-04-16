/**https://leetcode.com/problems/find-right-interval/ */
//You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
//The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
//Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.


/**
 * @param {number[][]} intervals
 * @return {number[]}
 */
var findRightInterval = function(intervals) {
    let n = intervals.length;
    let result = [];
    let map = new Map();
    for(let i = 0; i < n; i++){
        let [start, end] = intervals[i];
        map.set(start, i);
    }
    let sorted = [...map.keys()].sort((a, b) => a - b);
    for(let i = 0; i < n; i++){
        let [start, end] = intervals[i];
        let index = binarySearch(sorted, end);
        if(index == -1){
            result.push(-1);
        }else{
            result.push(map.get(sorted[index]));
        }
    }
    return result;
    
    
};

    