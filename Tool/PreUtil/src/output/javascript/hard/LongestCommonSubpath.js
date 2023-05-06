/**https://leetcode.com/problems/longest-common-subpath/ */
//There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.
//There are m friends numbered from 0 to m - 1 who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city more than once, but the same city will not be listed consecutively.
//Given an integer n and a 2D integer array paths where paths[i] is an integer array representing the path of the ith friend, return the length of the longest common subpath that is shared by every friend's path, or 0 if there is no common subpath at all.
//A subpath of a path is a contiguous sequence of cities within that path.


/**
 * @param {number} n
 * @param {number[][]} paths
 * @return {number}
 */
var longestCommonSubpath = function(n, paths) {
    let result = 0;
    let map = new Map();
    let max = 0;
    for (let i = 0; i < paths.length; i++) {
        let path = paths[i];
        for (let j = 0; j < path.length; j++) {
            let city = path[j];
            if (!map.has(city)) {
                map.set(city, 1);
            } else {
                map.set(city, map.get(city) + 1);
            }
        }
    }
    for (let i = 0; i < paths.length; i++) {
        let path = paths[i];
        for (let j = 0; j < path.length; j++) {
            let city = path[j];
            if (map.get(city) === paths.length) {
                max = Math.max(max, city);
            }
        }
    }
    return max;
    
};

    