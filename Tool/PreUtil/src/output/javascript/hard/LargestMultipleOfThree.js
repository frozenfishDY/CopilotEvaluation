/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.


/**
 * @param {number[]} digits
 * @return {string}
 */
var largestMultipleOfThree = function(digits) {
    let sum = 0;
    let count = new Array(10).fill(0);
    for(let i = 0; i < digits.length; i++){
        sum += digits[i];
        count[digits[i]]++;
    }
    if(sum % 3 == 1){
        if(count[1] > 0){
            count[1]--;
        }else if(count[4] > 0){
            count[4]--;
        }else if(count[7] > 0){
            count[7]--;
        }else if(count[2] > 1){
            count[2] -= 2;
        }else if(count[5] > 1){
            count[5] -= 2;
        }else if(count[8] > 1){
            count[8] -= 2;
        }else if(count[2] > 0 && count[5] > 0){
            count[2]--;
            count[5]--;
        }else if(count[2] > 0 && count[8] > 0){
            count[2]--;
            count[8]--;
        }else if(count[5] > 0 && count[8] > 0){
            count[5]--;
            count[8]--;
        }else{
            return "";
        }
    }else if(sum % 3 == 2){
        if(count[2] > 0){
            count[2]--;
        }else if(count[5] > 0){
            count[5]--;
        }else if(count[8] > 0){
            count[8]--;
        }else if(count[1] > 1){
            count[1] -= 2;
        }else if(count[4] > 1){
            count[4] -= 2;
        }else if(count[7] > 1){
            count[7] -= 2;
        }else if(count[1] > 0 && count[4] > 0){
            count[1]--;
            count[4]--;
        }else if(count[1] > 0 && count[7] > 0){
            count[1]--;
            count[7]--;
        }else if(count[4] > 0 && count[7] > 0){
            count[4]--;
            count[7]--;
        }else{
            return "";
        }
    }
    let res = "";
    for(let i = 9; i >= 0; i--){
        while(count[i] > 0){
            res += i;
            count[i]--;
        }
    }
    if(res.length > 0 && res[0] == '0') return "0";
    return res;
    
    
};

    