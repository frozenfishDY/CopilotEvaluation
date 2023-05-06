/**https://leetcode.com/problems/graph-connectivity-with-threshold/ */
//We have n cities labeled from 1 to n. Two different cities with labels x and y are directly connected by a bidirectional road if and only if x and y share a common divisor strictly greater than some threshold. More formally, cities with labels x and y have a road between them if there exists an integer z such that all of the following are true:
//x % z == 0,
//y % z == 0, and
//z > threshold.
//Given the two integers, n and threshold, and an array of queries, you must determine for each queries[i] = [ai, bi] if cities ai and bi are connected directly or indirectly. (i.e. there is some path between them).
//Return an array answer, where answer.length == queries.length and answer[i] is true if for the ith query, there is a path between ai and bi, or answer[i] is false if there is no path.


/**
 * @param {number} n
 * @param {number} threshold
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var areConnected = function(n, threshold, queries) {
    let uf = new UnionFind(n);
    for(let i = threshold + 1; i <= n; i++){
        for(let j = i + i; j <= n; j += i){
            uf.union(i, j);
        }
    }
    let res = [];
    for(let query of queries){
        let [a, b] = query;
        res.push(uf.find(a) == uf.find(b));
    }
    return res;
    
    
};

    