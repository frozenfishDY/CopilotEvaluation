/**https://leetcode.com/problems/remove-k-digits/ */
//Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var removeKdigits = function(num, k) {
    let n = num.length;
    let stack = [];
    let i = 0;
    while(i < n){
        while(k > 0 && stack.length > 0 && stack[stack.length - 1] > num[i]){
            stack.pop();
            k--;
        }
        stack.push(num[i]);
        i++;
    }
    while(k > 0){
        stack.pop();
        k--;
    }
    let result = "";
    while(stack.length > 0){
        result = stack.pop() + result;
    }
    while(result.length > 1 && result.charAt(0) == "0"){
        result = result.substring(1);
    }
    return result == "" ? "0" : result;
    
};

    