/**https://leetcode.com/problems/most-beautiful-item-for-each-query/ */
//You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
//You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.
//Return an array answer of the same length as queries where answer[j] is the answer to the jth query.


/**
 * @param {number[][]} items
 * @param {number[]} queries
 * @return {number[]}
 */
var maximumBeauty = function(items, queries) {
    let max = 0;
    let map = new Map();
    for (let i = 0; i < items.length; i++) {
        max = Math.max(max, items[i][1]);
        if (map.has(items[i][0])) {
            map.set(items[i][0], Math.max(map.get(items[i][0]), items[i][1]));
        } else {
            map.set(items[i][0], items[i][1]);
        }
    }
    let arr = Array.from(map).sort((a, b) => a[0] - b[0]);
    for (let i = 1; i < arr.length; i++) {
        arr[i][1] = Math.max(arr[i][1], arr[i - 1][1]);
    }
    let res = [];
    for (let i = 0; i < queries.length; i++) {
        let idx = binarySearch(arr, queries[i]);
        if (idx === -1) {
            res.push(0);
        } else {
            res.push(arr[idx][1]);
        }
    }
    return res;
    
    
};

    