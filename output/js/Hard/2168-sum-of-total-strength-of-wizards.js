/**https://leetcode.com/problems/sum-of-total-strength-of-wizards/ */
//As the ruler of a kingdom, you have an army of wizards at your command.
//You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:
//The strength of the weakest wizard in the group.
//The total of all the individual strengths of the wizards in the group.
//Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} strength
 * @return {number}
 */
var totalStrength = function(strength) {
    let mod = 1000000007;
    let n = strength.length;
    let left = new Array(n);
    let right = new Array(n);
    let stack = [];
    for(let i = 0; i < n; i++){
        while(stack.length > 0 && strength[stack[stack.length - 1]] >= strength[i]){
            stack.pop();
        }
        left[i] = stack.length == 0 ? -1 : stack[stack.length - 1];
        stack.push(i);
    }
    stack = [];
    for(let i = n - 1; i >= 0; i--){
        while(stack.length > 0 && strength[stack[stack.length - 1]] > strength[i]){
            stack.pop();
        }
        right[i] = stack.length == 0 ? n : stack[stack.length - 1];
        stack.push(i);
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        let l = i - left[i];
        let r = right[i] - i;
        result = (result + strength[i] * l * r) % mod;
    }
    return result;
    
};

    