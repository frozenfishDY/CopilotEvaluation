/**https://leetcode.com/problems/minimum-interval-to-include-each-query/ */
//You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
//You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
//Return an array containing the answers to the queries.


/**
 * @param {number[][]} intervals
 * @param {number[]} queries
 * @return {number[]}
 */
var minInterval = function(intervals, queries) {
    let result = [];
    let intervalMap = new Map();
    for (let i = 0; i < intervals.length; i++) {
        let interval = intervals[i];
        let left = interval[0];
        let right = interval[1];
        let size = right - left + 1;
        if (!intervalMap.has(size)) {
            intervalMap.set(size, []);
        }
        intervalMap.get(size).push(left);
    }
    let intervalArray = [];
    for (let [key, value] of intervalMap) {
        intervalArray.push([key, value]);
    }
    intervalArray.sort((a, b) => a[0] - b[0]);
    for (let i = 0; i < queries.length; i++) {
        let query = queries[i];
        let min = Number.MAX_SAFE_INTEGER;
        for (let j = 0; j < intervalArray.length; j++) {
            let interval = intervalArray[j];
            let size = interval[0];
            let leftArray = interval[1];
            if (size > min) {
                break;
            }
            for (let k = 0; k < leftArray.length; k++) {
                let left = leftArray[k];
                if (left <= query) {
                    min = Math.min(min, size);
                }
            }
        }
        if (min == Number.MAX_SAFE_INTEGER) {
            result.push(-1);
        } else {
            result.push(min);
        }
    }
    return result;
    
};

    