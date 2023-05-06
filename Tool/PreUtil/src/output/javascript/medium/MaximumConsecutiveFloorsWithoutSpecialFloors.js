/**https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/ */
//Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.
//You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.
//Return the maximum number of consecutive floors without a special floor.


/**
 * @param {number} bottom
 * @param {number} top
 * @param {number[]} special
 * @return {number}
 */
var maxConsecutive = function(bottom, top, special) {
    let n = top - bottom + 1;
    let count = 0;
    let max = 0;
    let map = {};
    for (let i = 0; i < special.length; i++) {
        map[special[i]] = true;
    }
    for (let i = bottom; i <= top; i++) {
        if (map[i] === undefined) {
            count++;
            max = Math.max(max, count);
        } else {
            count = 0;
        }
    }
    return max;
    
};

    