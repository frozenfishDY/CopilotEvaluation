/**https://leetcode.com/problems/evaluate-reverse-polish-notation/ */
//You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//Evaluate the expression. Return an integer that represents the value of the expression.


/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    let stack = [];
    for(let i = 0; i < tokens.length; i++){
        if(tokens[i] == '+'){
            let a = stack.pop();
            let b = stack.pop();
            stack.push(a + b);
        }
        else if(tokens[i] == '-'){
            let a = stack.pop();
            let b = stack.pop();
            stack.push(b - a);
        }
        else if(tokens[i] == '*'){
            let a = stack.pop();
            let b = stack.pop();
            stack.push(a * b);
        }
        else if(tokens[i] == '/'){
            let a = stack.pop();
            let b = stack.pop();
            stack.push(Math.trunc(b / a));
        }
        else{
            stack.push(parseInt(tokens[i]));
        }
    }
    return stack.pop();
    
};

    