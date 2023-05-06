/**https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/ */
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.


/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findLeastNumOfUniqueInts = function(arr, k) {
    let map = new Map();
    for (let num of arr) {
        map.set(num, (map.get(num) || 0) + 1);
    }
    let arr2 = Array.from(map.values());
    arr2.sort((a, b) => a - b);
    let i = 0;
    while (i < arr2.length && k >= arr2[i]) {
        k -= arr2[i];
        i++;
    }
    return arr2.length - i;
    
};

    