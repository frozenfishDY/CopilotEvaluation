/**https://leetcode.com/problems/loud-and-rich/ */
//There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.
//You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).
//Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.


/**
 * @param {number[][]} richer
 * @param {number[]} quiet
 * @return {number[]}
 */
var loudAndRich = function(richer, quiet) {
    let n = quiet.length;
    let result = new Array(n).fill(-1);
    let graph = new Array(n).fill(0).map(() => new Array());
    for(let i = 0; i < richer.length; i++){
        let [a, b] = richer[i];
        graph[b].push(a);
    }
    for(let i = 0; i < n; i++){
        dfs(i, graph, quiet, result);
    }
    return result;
    
    
};

    