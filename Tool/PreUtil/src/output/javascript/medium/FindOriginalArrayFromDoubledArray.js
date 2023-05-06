/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.


/**
 * @param {number[]} changed
 * @return {number[]}
 */
var findOriginalArray = function(changed) {
    let map = new Map();
    let result = [];
    for (let i = 0; i < changed.length; i++) {
        if (map.has(changed[i])) {
            map.set(changed[i], map.get(changed[i]) + 1);
        } else {
            map.set(changed[i], 1);
        }
    }
    let sorted = [...map.keys()].sort((a, b) => a - b);
    for (let i = 0; i < sorted.length; i++) {
        let num = sorted[i];
        let count = map.get(num);
        if (count === 0) {
            continue;
        }
        if (!map.has(num * 2) || map.get(num * 2) < count) {
            return [];
        }
        for (let j = 0; j < count; j++) {
            result.push(num);
            map.set(num, map.get(num) - 1);
            map.set(num * 2, map.get(num * 2) - 1);
        }
    }
    return result;
    
};

    