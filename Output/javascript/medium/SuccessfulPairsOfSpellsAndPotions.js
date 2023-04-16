/**https://leetcode.com/problems/successful-pairs-of-spells-and-potions/ */
//You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
//You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
//Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.


/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
var successfulPairs = function(spells, potions, success) {
    let n = spells.length;
    let m = potions.length;
    let pairs = new Array(n);
    for (let i = 0; i < n; i++) {
        let count = 0;
        for (let j = 0; j < m; j++) {
            if (spells[i] * potions[j] >= success) {
                count++;
            }
        }
        pairs[i] = count;
    }
    return pairs;
    
};

    