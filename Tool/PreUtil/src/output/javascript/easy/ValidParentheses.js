/**https://leetcode.com/problems/valid-parentheses/ */
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.


/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    for(let i = 0; i < s.length; i++){
        let curr = s[i];
        if(curr === '(' || curr === '{' || curr === '['){
            stack.push(curr);
        }else{
            let last = stack.pop();
            if(curr === ')' && last !== '(') return false;
            if(curr === '}' && last !== '{') return false;
            if(curr === ']' && last !== '[') return false;
        }
    }
    return stack.length === 0;
    
    
};

    