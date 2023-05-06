/**https://leetcode.com/problems/split-array-into-fibonacci-sequence/ */
//You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
//Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
//f.length >= 3, and
//f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
//Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.


/**
 * @param {string} num
 * @return {number[]}
 */
var splitIntoFibonacci = function(num) {
    let result = [];
    let n = num.length;
    let backtrack = function(index){
        if(index == n && result.length >= 3){
            return true;
        }
        let current = 0;
        for(let i = index; i < n; i++){
            if(i > index && num[index] == '0'){
                break;
            }
            current = current * 10 + (num[i] - '0');
            if(current > 2 ** 31 - 1){
                break;
            }
            let len = result.length;
            if(len >= 2 && current > result[len - 1] + result[len - 2]){
                break;
            }
            if(len <= 1 || current == result[len - 1] + result[len - 2]){
                result.push(current);
                if(backtrack(i + 1)){
                    return true;
                }
                result.pop();
            }
        }
        return false;
    }
    backtrack(0);
    return result;
    
};

    