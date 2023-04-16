/**https://leetcode.com/problems/minimum-cost-to-set-cooking-time/ */
//A generic microwave supports cooking times for:
//at least 1 second.
//at most 99 minutes and 99 seconds.
//To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,
//You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
//You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
//You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
//You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
//You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.
//There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.
//Return the minimum cost to set targetSeconds seconds of cooking time.
//Remember that one minute consists of 60 seconds.


/**
 * @param {number} startAt
 * @param {number} moveCost
 * @param {number} pushCost
 * @param {number} targetSeconds
 * @return {number}
 */
var minCostSetTime = function(startAt, moveCost, pushCost, targetSeconds) {
    let min = Number.MAX_VALUE;
    let minutes = Math.floor(targetSeconds / 60);
    let seconds = targetSeconds % 60;
    let arr = [minutes, seconds];
    let set = new Set();
    let visited = new Set();
    let queue = [];
    queue.push([startAt, 0]);
    while (queue.length > 0) {
        let [digit, cost] = queue.shift();
        if (visited.has(digit)) {
            continue;
        }
        visited.add(digit);
        if (set.size === 2) {
            let sum = 0;
            for (let num of set) {
                sum += num;
            }
            if (sum === targetSeconds) {
                min = Math.min(min, cost);
            }
        }
        for (let i = 0; i < arr.length; i++) {
            let diff = Math.abs(digit - arr[i]);
            let newCost = cost + diff * moveCost + pushCost;
            if (newCost < min) {
                queue.push([arr[i], newCost]);
                set.add(arr[i]);
            }
        }
    }
    return min;
    
};

    