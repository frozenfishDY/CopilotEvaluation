/**https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ */
//In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
//Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
//If it cannot be done, return -1.


/**
 * @param {number[]} tops
 * @param {number[]} bottoms
 * @return {number}
 */
var minDominoRotations = function(tops, bottoms) {
    let n = tops.length;
    let result = Number.MAX_SAFE_INTEGER;
    for(let i = 1; i <= 6; i++){
        let count = 0;
        let flag = true;
        for(let j = 0; j < n; j++){
            if(tops[j] != i && bottoms[j] != i){
                flag = false;
                break;
            }
            else if(tops[j] != i){
                count++;
            }
        }
        if(flag){
            result = Math.min(result, count);
        }
    }
    for(let i = 1; i <= 6; i++){
        let count = 0;
        let flag = true;
        for(let j = 0; j < n; j++){
            if(tops[j] != i && bottoms[j] != i){
                flag = false;
                break;
            }
            else if(bottoms[j] != i){
                count++;
            }
        }
        if(flag){
            result = Math.min(result, count);
        }
    }
    return result == Number.MAX_SAFE_INTEGER ? -1 : result;
    
    
};

    