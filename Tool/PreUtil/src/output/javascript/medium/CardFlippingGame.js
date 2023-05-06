/**https://leetcode.com/problems/card-flipping-game/ */
//You are given two 0-indexed integer arrays fronts and backs of length n, where the ith card has the positive integer fronts[i] printed on the front and backs[i] printed on the back. Initially, each card is placed on a table such that the front number is facing up and the other is facing down. You may flip over any number of cards (possibly zero).
//After flipping the cards, an integer is considered good if it is facing down on some card and not facing up on any card.
//Return the minimum possible good integer after flipping the cards. If there are no good integers, return 0.


/**
 * @param {number[]} fronts
 * @param {number[]} backs
 * @return {number}
 */
var flipgame = function(fronts, backs) {
    let n = fronts.length;
    let set = new Set();
    for(let i = 0; i < n; i++){
        if(fronts[i] == backs[i]){
            set.add(fronts[i]);
        }
    }
    let result = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < n; i++){
        if(!set.has(fronts[i])){
            result = Math.min(result, fronts[i]);
        }
        if(!set.has(backs[i])){
            result = Math.min(result, backs[i]);
        }
    }
    return result == Number.MAX_SAFE_INTEGER ? 0 : result;
    
};

    