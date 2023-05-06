/**https://leetcode.com/problems/score-of-parentheses/ */
//Given a balanced parentheses string s, return the score of the string.
//The score of a balanced parentheses string is based on the following rule:
//"()" has score 1.
//AB has score A + B, where A and B are balanced parentheses strings.
//(A) has score 2 * A, where A is a balanced parentheses string.


/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function(s) {
    let stack = [];
    let result = 0;
    for(let i = 0; i < s.length; i++){
        if(s[i] == '('){
            stack.push(result);
            result = 0;
        }else{
            result = stack.pop() + Math.max(result * 2, 1);
        }
    }
    return result;
    
};

    