/**https://leetcode.com/problems/generate-parentheses/ */
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 


/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let result = [];
    if(n == 0){
        return result;
    }
    let queue = [];
    queue.push({str: "", open: 0, close: 0});
    while(queue.length > 0){
        let current = queue.shift();
        if(current.open == n && current.close == n){
            result.push(current.str);
        }else{
            if(current.open < n){
                queue.push({str: current.str + "(", open: current.open + 1, close: current.close});
            }
            if(current.close < current.open){
                queue.push({str: current.str + ")", open: current.open, close: current.close + 1});
            }
        }
    }
    return result;
    
};

    