/**https://leetcode.com/problems/jump-game-iii/ */
//Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
//Notice that you can not jump outside of the array at any time.


/**
 * @param {number[]} arr
 * @param {number} start
 * @return {boolean}
 */
var canReach = function(arr, start) {
    let n = arr.length;
    let visited = new Array(n).fill(false);
    let queue = [start];
    while(queue.length > 0){
        let i = queue.shift();
        if(arr[i] == 0){
            return true;
        }
        if(!visited[i]){
            visited[i] = true;
            if(i + arr[i] < n){
                queue.push(i + arr[i]);
            }
            if(i - arr[i] >= 0){
                queue.push(i - arr[i]);
            }
        }
    }
    return false;
    
};

    