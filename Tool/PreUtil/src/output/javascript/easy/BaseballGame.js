/**https://leetcode.com/problems/baseball-game/ */
//You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
//You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
//An integer x.
//Record a new score of x.
//'+'.
//Record a new score that is the sum of the previous two scores.
//'D'.
//Record a new score that is the double of the previous score.
//'C'.
//Invalidate the previous score, removing it from the record.
//Return the sum of all the scores on the record after applying all the operations.
//The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.


/**
 * @param {string[]} operations
 * @return {number}
 */
var calPoints = function(operations) {
    let stack = [];
    let sum = 0;
    for(let i = 0; i < operations.length; i++){
        if(operations[i] == 'C'){
            sum -= stack.pop();
        }else if(operations[i] == 'D'){
            let last = stack[stack.length - 1];
            stack.push(last * 2);
            sum += last * 2;
        }else if(operations[i] == '+'){
            let last = stack[stack.length - 1];
            let secondLast = stack[stack.length - 2];
            stack.push(last + secondLast);
            sum += last + secondLast;
        }else{
            let num = parseInt(operations[i]);
            stack.push(num);
            sum += num;
        }
    }
    return sum;
    
};

    