/**https://leetcode.com/problems/evaluate-division/ */
//You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
//You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
//Return the answers to all queries. If a single answer cannot be determined, return -1.0.
//Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.


/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
    let result = [];
    let map = new Map();
    for(let i = 0; i < equations.length; i++){
        let [a, b] = equations[i];
        let value = values[i];
        if(!map.has(a)){
            map.set(a, new Map());
        }
        if(!map.has(b)){
            map.set(b, new Map());
        }
        map.get(a).set(b, value);
        map.get(b).set(a, 1 / value);
    }
    for(let i = 0; i < queries.length; i++){
        let [a, b] = queries[i];
        if(!map.has(a) || !map.has(b)){
            result.push(-1);
        }else{
            let visited = new Set();
            let value = dfs(a, b, map, visited);
            result.push(value);
        }
    }
    return result;
    
    
};

    