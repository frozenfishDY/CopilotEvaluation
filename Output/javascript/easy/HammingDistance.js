/**https://leetcode.com/problems/hamming-distance/ */
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Given two integers x and y, return the Hamming distance between them.


/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let count = 0;
    while(x != 0 || y != 0){
        if(x % 2 != y % 2){
            count++;
        }
        x = Math.floor(x / 2);
        y = Math.floor(y / 2);
    }
    return count;
    
};

    