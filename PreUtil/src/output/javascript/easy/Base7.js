/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.


/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    let ans = "";
    let neg = false;
    if(num < 0){
        neg = true;
        num = num * -1;
    }
    while(num > 0){
        ans = num % 7 + ans;
        num = Math.floor(num / 7);
    }
    if(neg){
        ans = "-" + ans;
    }
    return ans;
    
};

    