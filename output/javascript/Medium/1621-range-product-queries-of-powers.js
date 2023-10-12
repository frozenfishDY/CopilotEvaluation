/**https://leetcode.com/problems/range-product-queries-of-powers/ */
//Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.
//You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.
//Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.
// 
//Example 1:
//Input: n = 15, queries = [[0,1],[2,2],[0,3]]
//Output: [2,4,64]
//Explanation:
//For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
//Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
//Answer to 2nd query: powers[2] = 4.
//Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
//Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
//Example 2:
//Input: n = 2, queries = [[0,0]]
//Output: [2]
//Explanation:
//For n = 2, powers = [2].
//The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.
// 
//Constraints:
//	1 <= n <= 109
//	1 <= queries.length <= 105
//	0 <= starti <= endi < powers.length
/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[]}
 */
var productQueries = function(n, queries) {
    let mod = 1e9 + 7;
    let res = [];
    let powers = [];
    let sum = 0;
    for (let i = 0; sum < n; i++) {
        let cur = 1 << i;
        powers.push(cur);
        sum += cur;
    }
    let m = powers.length;
    for (let query of queries) {
        let [left, right] = query;
        let start = left;
        let end = right;
        while (start < end) {
            let mid = start + ((end - start) >> 1);
            if (powers[mid] <= left) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        left = start;
        start = left;
        end = right;
        while (start < end) {
            let mid = start + ((end - start) >> 1) + 1;
            if (powers[mid] <= right) {
                start = mid;
            } else {
                end = mid - 1;
            }
        }
        right = start;
        let cur = 1;
        for (let i = left; i <= right; i++) {
            cur = (cur * powers[i]) % mod;
        }
        res.push(cur);
    }
    return res;
};