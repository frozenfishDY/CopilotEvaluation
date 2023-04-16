/**https://leetcode.com/problems/basic-calculator-ii/ */
//Given a string s which represents an expression, evaluate this expression and return its value. 
//The integer division should truncate toward zero.
//You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
//Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    let stack = [];
    let num = 0;
    let sign = '+';
    for(let i = 0; i < s.length; i++){
        if(!isNaN(s[i]) && s[i] != ' '){
            num = num * 10 + parseInt(s[i]);
        }
        if(isNaN(s[i]) || i == s.length - 1){
            if(sign == '+'){
                stack.push(num);
            }else if(sign == '-'){
                stack.push(-num);
            }else if(sign == '*'){
                stack.push(stack.pop() * num);
            }else if(sign == '/'){
                stack.push(Math.trunc(stack.pop() / num));
            }
            sign = s[i];
            num = 0;
        }
    }
    let result = 0;
    while(stack.length > 0){
        result += stack.pop();
    }
    return result;
    
};

    