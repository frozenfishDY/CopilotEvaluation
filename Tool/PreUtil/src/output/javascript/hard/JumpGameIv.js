/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//i + 1 where: i + 1 < arr.length.
//i - 1 where: i - 1 >= 0.
//j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.


/**
 * @param {number[]} arr
 * @return {number}
 */
var minJumps = function(arr) {
    let map = new Map();
    for(let i = 0; i < arr.length; i++){
        if(map.has(arr[i])){
            map.get(arr[i]).push(i);
        }else{
            map.set(arr[i], [i]);
        }
    }
    let visited = new Set();
    let queue = [0];
    let step = 0;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let curr = queue.shift();
            if(curr == arr.length - 1) return step;
            if(!visited.has(curr)){
                visited.add(curr);
                if(curr - 1 >= 0) queue.push(curr - 1);
                if(curr + 1 < arr.length) queue.push(curr + 1);
                if(map.has(arr[curr])){
                    for(let j of map.get(arr[curr])){
                        queue.push(j);
                    }
                    map.delete(arr[curr]);
                }
            }
        }
        step++;
    }
    return step;
    
};

    