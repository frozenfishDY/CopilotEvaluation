/**https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/ */
//You have the task of delivering some boxes from storage to their ports using only one ship. However, this ship has a limit on the number of boxes and the total weight that it can carry.
//You are given an array boxes, where boxes[i] = [portsi, weighti], and three integers portsCount, maxBoxes, and maxWeight.
//portsi is the port where you need to deliver the ith box and weightsi is the weight of the ith box.
//portsCount is the number of ports.
//maxBoxes and maxWeight are the respective box and weight limits of the ship.
//The boxes need to be delivered in the order they are given. The ship will follow these steps:
//The ship will take some number of boxes from the boxes queue, not violating the maxBoxes and maxWeight constraints.
//For each loaded box in order, the ship will make a trip to the port the box needs to be delivered to and deliver it. If the ship is already at the correct port, no trip is needed, and the box can immediately be delivered.
//The ship then makes a return trip to storage to take more boxes from the queue.
//The ship must end at storage after all the boxes have been delivered.
//Return the minimum number of trips the ship needs to make to deliver all boxes to their respective ports.


/**
 * @param {number[][]} boxes
 * @param {number} portsCount
 * @param {number} maxBoxes
 * @param {number} maxWeight
 * @return {number}
 */
var boxDelivering = function(boxes, portsCount, maxBoxes, maxWeight) {
    let n = boxes.length;
    let dp = new Array(n + 1).fill(0);
    let last = new Array(n + 1).fill(0);
    let j = 0;
    let weight = 0;
    for(let i = 0; i < n; i++){
        while(j < n && j - i < maxBoxes && weight + boxes[j][1] <= maxWeight){
            weight += boxes[j][1];
            if(j == 0 || boxes[j][0] != boxes[j - 1][0]){
                last[j] = j;
            }else{
                last[j] = last[j - 1];
            }
            j++;
        }
        dp[j] = dp[i] + 2;
        if(last[i] < j){
            dp[j] = Math.min(dp[j], dp[last[i]] + 1);
        }
        weight -= boxes[i][1];
    }
    return dp[n];
    
};

    