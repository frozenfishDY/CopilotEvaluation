/**https://leetcode.com/problems/longest-valid-parentheses/ */
//Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.


/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let stack = [];
    let max = 0;
    let start = 0;
    for(let i = 0; i < s.length; i++){
        if(s[i] == '('){
            stack.push(i);
        }else{
            if(stack.length == 0){
                start = i + 1;
            }else{
                stack.pop();
                if(stack.length == 0){
                    max = Math.max(max, i - start + 1);
                }else{
                    max = Math.max(max, i - stack[stack.length - 1]);
                }
            }
        }
    }
    return max;
    
};

    