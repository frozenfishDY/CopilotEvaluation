/**https://leetcode.com/problems/binary-number-with-alternating-bits/ */
//Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.


/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function(n) {
    let str = n.toString(2);
    for(let i = 0; i < str.length - 1; i++){
        if(str[i] == str[i + 1]){
            return false;
        }
    }
    return true;
    
};

    