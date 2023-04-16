/**https://leetcode.com/problems/flower-planting-with-no-adjacent/ */
//You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
//All gardens have at most 3 paths coming into or leaving it.
//Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
//Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.


/**
 * @param {number} n
 * @param {number[][]} paths
 * @return {number[]}
 */
var gardenNoAdj = function(n, paths) {
    let graph = new Array(n).fill(0).map(() => new Array());
    let result = new Array(n).fill(0);
    for(let i = 0; i < paths.length; i++){
        let [a, b] = paths[i];
        graph[a - 1].push(b - 1);
        graph[b - 1].push(a - 1);
    }
    for(let i = 0; i < n; i++){
        let used = new Array(5).fill(false);
        for(let j = 0; j < graph[i].length; j++){
            used[result[graph[i][j]]] = true;
        }
        for(let j = 1; j <= 4; j++){
            if(!used[j]){
                result[i] = j;
                break;
            }
        }
    }
    return result;
    
};

    