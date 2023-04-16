/**https://leetcode.com/problems/hand-of-straights/ */
//Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
//Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


/**
 * @param {number[]} hand
 * @param {number} groupSize
 * @return {boolean}
 */
var isNStraightHand = function(hand, groupSize) {
    if(hand.length % groupSize != 0){
        return false;
    }
    let map = {};
    for(let i = 0; i < hand.length; i++){
        let num = hand[i];
        if(map[num] == undefined){
            map[num] = 0;
        }
        map[num]++;
    }
    let keys = Object.keys(map);
    keys.sort((a, b) => a - b);
    for(let i = 0; i < keys.length; i++){
        let key = keys[i];
        let count = map[key];
        if(count == 0){
            continue;
        }
        for(let j = 1; j < groupSize; j++){
            let next = parseInt(key) + j;
            if(map[next] == undefined || map[next] < count){
                return false;
            }
            map[next] -= count;
        }
    }
    return true;
    
    
};

    