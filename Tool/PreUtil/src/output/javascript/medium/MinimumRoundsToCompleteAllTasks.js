/**https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/ */
//You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.
//Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.


/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function(tasks) {
    let n = tasks.length;
    let result = 0;
    let left = 0;
    let right = n - 1;
    let count = 0;
    while (left < right) {
        if (tasks[left] < tasks[right]) {
            left++;
        } else if (tasks[left] > tasks[right]) {
            right--;
        } else {
            left++;
            right--;
        }
        count++;
    }
    if (left === right) {
        result = 1;
    }
    if (count > 0) {
        result += Math.ceil(count / 3);
    }
    return result;
    
};

    