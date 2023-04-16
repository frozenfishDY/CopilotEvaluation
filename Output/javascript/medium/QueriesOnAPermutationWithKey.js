/**https://leetcode.com/problems/queries-on-a-permutation-with-key/ */
//Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:
//In the beginning, you have the permutation P=[1,2,3,...,m].
//For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
//Return an array containing the result for the given queries.


/**
 * @param {number[]} queries
 * @param {number} m
 * @return {number[]}
 */
var processQueries = function(queries, m) {
    let p = [];
    for (let i = 1; i <= m; i++) {
        p.push(i);
    }
    let result = [];
    for (let i = 0; i < queries.length; i++) {
        let index = p.indexOf(queries[i]);
        result.push(index);
        p.splice(index, 1);
        p.unshift(queries[i]);
    }
    return result;
    
};

    