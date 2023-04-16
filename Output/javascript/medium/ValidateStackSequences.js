/**https://leetcode.com/problems/validate-stack-sequences/ */
//Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.


/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    let stack = [];
    let i = 0;
    for(let j = 0; j < pushed.length; j++){
        stack.push(pushed[j]);
        while(stack.length > 0 && stack[stack.length - 1] == popped[i]){
            stack.pop();
            i++;
        }
    }
    return stack.length == 0;
    
};

    