/**https://leetcode.com/problems/different-ways-to-add-parentheses/ */
//Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
//The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.


/**
 * @param {string} expression
 * @return {number[]}
 */
var diffWaysToCompute = function(expression) {
    let result = [];
    for(let i = 0; i < expression.length; i++){
        let char = expression[i];
        if(char === '+' || char === '-' || char === '*'){
            let left = diffWaysToCompute(expression.substring(0, i));
            let right = diffWaysToCompute(expression.substring(i + 1));
            for(let j = 0; j < left.length; j++){
                for(let k = 0; k < right.length; k++){
                    if(char === '+'){
                        result.push(left[j] + right[k]);
                    }else if(char === '-'){
                        result.push(left[j] - right[k]);
                    }else{
                        result.push(left[j] * right[k]);
                    }
                }
            }
        }
    }
    if(result.length === 0){
        result.push(parseInt(expression));
    }
    return result;
    
};

    