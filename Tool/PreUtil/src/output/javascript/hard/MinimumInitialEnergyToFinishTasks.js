/**https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/ */
//You are given an array tasks where tasks[i] = [actuali, minimumi]:
//actuali is the actual amount of energy you spend to finish the ith task.
//minimumi is the minimum amount of energy you require to begin the ith task.
//For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.
//You can finish the tasks in any order you like.
//Return the minimum initial amount of energy you will need to finish all the tasks.


/**
 * @param {number[][]} tasks
 * @return {number}
 */
var minimumEffort = function(tasks) {
    tasks.sort((a, b) => a[1] - a[0] - (b[1] - b[0]));
    let res = 0;
    for(let i = 0; i < tasks.length; i++){
        res = Math.max(res + tasks[i][0], tasks[i][1]);
    }
    return res;
    
};

    