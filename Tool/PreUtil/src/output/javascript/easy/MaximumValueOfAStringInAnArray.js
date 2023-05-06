/**https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/ */
//The value of an alphanumeric string can be defined as:
//The numeric representation of the string in base 10, if it comprises of digits only.
//The length of the string, otherwise.
//Given an array strs of alphanumeric strings, return the maximum value of any string in strs.


/**
 * @param {string[]} strs
 * @return {number}
 */
var maximumValue = function(strs) {
    let max = 0;
    for(let i = 0; i < strs.length; i++){
        let val = 0;
        for(let j = 0; j < strs[i].length; j++){
            if(strs[i].charCodeAt(j) >= 48 && strs[i].charCodeAt(j) <= 57){
                val *= 10;
                val += strs[i].charCodeAt(j) - 48;
            }else{
                val = strs[i].length;
                break;
            }
        }
        if(val > max){
            max = val;
        }
    }
    return max;
    
};

    