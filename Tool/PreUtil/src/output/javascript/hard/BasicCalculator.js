/**https://leetcode.com/problems/basic-calculator/ */
//Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
//Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    let stack = [];
    let sign = 1;
    let result = 0;
    let i = 0;
    while(i < s.length){
        if(s[i] === " "){
            i++;
        }else if(s[i] === "+"){
            sign = 1;
            i++;
        }else if(s[i] === "-"){
            sign = -1;
            i++;
        }else if(s[i] === "("){
            stack.push(result);
            stack.push(sign);
            result = 0;
            sign = 1;
            i++;
        }else if(s[i] === ")"){
            result = result * stack.pop() + stack.pop();
            i++;
        }else{
            let num = 0;
            while(i < s.length && s[i] >= "0" && s[i] <= "9"){
                num = num * 10 + s[i].charCodeAt() - "0".charCodeAt();
                i++;
            }
            result += sign * num;
        }
    }
    return result;
    
};

    