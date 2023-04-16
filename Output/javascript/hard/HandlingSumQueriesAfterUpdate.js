/**https://leetcode.com/problems/handling-sum-queries-after-update/ */
//You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
//For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
//For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
//For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
//Return an array containing all the answers to the third type queries.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[][]} queries
 * @return {number[]}
 */
var handleQuery = function(nums1, nums2, queries) {
    let n = nums1.length;
    let m = nums2.length;
    let result = [];
    for(let i = 0; i < queries.length; i++){
        let type = queries[i][0];
        if(type === 1){
            let l = queries[i][1];
            let r = queries[i][2];
            for(let j = l; j <= r; j++){
                nums1[j] = 1 - nums1[j];
            }
        }else if(type === 2){
            let p = queries[i][1];
            for(let j = 0; j < m; j++){
                nums2[j] += nums1[j] * p;
            }
        }else{
            let sum = 0;
            for(let j = 0; j < m; j++){
                sum += nums2[j];
            }
            result.push(sum);
        }
    }
    return result;
    
};

    