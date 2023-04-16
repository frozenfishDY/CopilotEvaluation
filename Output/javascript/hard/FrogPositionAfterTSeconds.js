/**https://leetcode.com/problems/frog-position-after-t-seconds/ */
//Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices, it jumps randomly to one of them with the same probability. Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.
//The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
//Return the probability that after t seconds the frog is on the vertex target. Answers within 10-5 of the actual answer will be accepted.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} t
 * @param {number} target
 * @return {number}
 */
var frogPosition = function(n, edges, t, target) {
    let map = new Map();
    for(let i = 0; i < edges.length; i++){
        let [a, b] = edges[i];
        if(map.has(a)){
            map.get(a).push(b);
        }else{
            map.set(a, [b]);
        }
        if(map.has(b)){
            map.get(b).push(a);
        }else{
            map.set(b, [a]);
        }
    }
    let visited = new Set();
    let queue = [1];
    let step = 0;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let curr = queue.shift();
            if(curr == target){
                if(step == t || map.get(curr).length == 1) return 1;
                else return 0;
            }
            if(!visited.has(curr)){
                visited.add(curr);
                let next = map.get(curr);
                for(let j = 0; j < next.length; j++){
                    if(!visited.has(next[j])){
                        queue.push(next[j]);
                    }
                }
            }
        }
        step++;
    }
    return 0;
    
};

    