/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.


/**
 * @param {number[]} nums
 * @return {number}
 */
var largestComponentSize = function(nums) {
    let parent = new Array(100001).fill(0);
    let size = new Array(100001).fill(1);
    for(let i = 0; i < nums.length; i++){
        parent[nums[i]] = nums[i];
    }
    let find = function(x){
        if(parent[x] === x){
            return x;
        }
        return parent[x] = find(parent[x]);
    };
    let union = function(x, y){
        let rootX = find(x);
        let rootY = find(y);
        if(rootX === rootY){
            return;
        }
        if(size[rootX] > size[rootY]){
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        else{
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    };
    for(let i = 0; i < nums.length; i++){
        for(let j = 2; j * j <= nums[i]; j++){
            if(nums[i] % j === 0){
                union(nums[i], j);
                union(nums[i], nums[i] / j);
            }
        }
    }
    let res = 0;
    for(let i = 0; i < nums.length; i++){
        res = Math.max(res, size[find(nums[i])]);
    }
    return res;
    
};

    