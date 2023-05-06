/**https://leetcode.com/problems/finding-the-users-active-minutes/ */
//You are given the logs for users' actions on LeetCode, and an integer k. The logs are represented by a 2D integer array logs where each logs[i] = [IDi, timei] indicates that the user with IDi performed an action at the minute timei.
//Multiple users can perform actions simultaneously, and a single user can perform multiple actions in the same minute.
//The user active minutes (UAM) for a given user is defined as the number of unique minutes in which the user performed an action on LeetCode. A minute can only be counted once, even if multiple actions occur during it.
//You are to calculate a 1-indexed array answer of size k such that, for each j (1 <= j <= k), answer[j] is the number of users whose UAM equals j.
//Return the array answer as described above.


/**
 * @param {number[][]} logs
 * @param {number} k
 * @return {number[]}
 */
var findingUsersActiveMinutes = function(logs, k) {
    let map = new Map();
    let result = new Array(k).fill(0);
    for (let i = 0; i < logs.length; i++) {
        let id = logs[i][0];
        let time = logs[i][1];
        if (map.has(id)) {
            map.get(id).add(time);
        } else {
            map.set(id, new Set([time]));
        }
    }
    for (let [key, value] of map) {
        result[value.size - 1]++;
    }
    return result;
    
};

    