/**https://leetcode.com/problems/intervals-between-identical-elements/ */
//You are given a 0-indexed array of n integers arr.
//The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval between arr[i] and arr[j] is |i - j|.
//Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the same value as arr[i].
//Note: |x| is the absolute value of x.


/**
 * @param {number[]} arr
 * @return {number[]}
 */
var getDistances = function(arr) {
    let map = new Map();
    for (let i = 0; i < arr.length; i++) {
        if (map.has(arr[i])) {
            map.get(arr[i]).push(i);
        } else {
            map.set(arr[i], [i]);
        }
    }
    let res = [];
    for (let i = 0; i < arr.length; i++) {
        let sum = 0;
        let list = map.get(arr[i]);
        for (let j = 0; j < list.length; j++) {
            sum += Math.abs(list[j] - i);
        }
        res.push(sum);
    }
    return res;
    
};

    