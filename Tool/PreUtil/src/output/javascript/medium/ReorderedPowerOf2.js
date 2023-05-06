/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.


/**
 * @param {number} n
 * @return {boolean}
 */
var reorderedPowerOf2 = function(n) {
    let count = new Array(10).fill(0);
    while(n > 0){
        count[n % 10]++;
        n = Math.floor(n / 10);
    }
    for(let i = 0; i < 31; i++){
        let temp = new Array(10).fill(0);
        let num = 1 << i;
        while(num > 0){
            temp[num % 10]++;
            num = Math.floor(num / 10);
        }
        if(isEqual(count, temp)){
            return true;
        }
    }
    return false;
    
    
};

    