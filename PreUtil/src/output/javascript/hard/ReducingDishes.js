/**https://leetcode.com/problems/reducing-dishes/ */
//A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
//Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
//Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
//Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.


/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(satisfaction) {
    satisfaction.sort((a, b) => b - a);
    let n = satisfaction.length;
    let sum = 0;
    let ans = 0;
    for(let i = 0; i < n; i++){
        sum += satisfaction[i];
        if(sum < 0) break;
        ans += sum;
    }
    return ans;
    
};

    