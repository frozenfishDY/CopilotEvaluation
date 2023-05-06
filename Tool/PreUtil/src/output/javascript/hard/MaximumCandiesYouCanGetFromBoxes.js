/**https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/ */
//You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
//status[i] is 1 if the ith box is open and 0 if the ith box is closed,
//candies[i] is the number of candies in the ith box,
//keys[i] is a list of the labels of the boxes you can open after opening the ith box.
//containedBoxes[i] is a list of the boxes you found inside the ith box.
//You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
//Return the maximum number of candies you can get following the rules above.


/**
 * @param {number[]} status
 * @param {number[]} candies
 * @param {number[][]} keys
 * @param {number[][]} containedBoxes
 * @param {number[]} initialBoxes
 * @return {number}
 */
var maxCandies = function(status, candies, keys, containedBoxes, initialBoxes) {
    let n = status.length;
    let visited = new Array(n).fill(false);
    let queue = [];
    for(let i = 0; i < initialBoxes.length; i++){
        if(status[initialBoxes[i]] == 1){
            queue.push(initialBoxes[i]);
        }
    }
    let res = 0;
    while(queue.length > 0){
        let box = queue.shift();
        if(visited[box]){
            continue;
        }
        visited[box] = true;
        res += candies[box];
        for(let i = 0; i < keys[box].length; i++){
            status[keys[box][i]] = 1;
            if(!visited[keys[box][i]]){
                queue.push(keys[box][i]);
            }
        }
        for(let i = 0; i < containedBoxes[box].length; i++){
            if(status[containedBoxes[box][i]] == 1){
                queue.push(containedBoxes[box][i]);
            }
        }
    }
    return res;
    
    
};

    