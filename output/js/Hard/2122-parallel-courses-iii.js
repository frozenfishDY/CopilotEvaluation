/**https://leetcode.com/problems/parallel-courses-iii/ */
//You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.
//You must find the minimum number of months needed to complete all the courses following these rules:
//You may start taking a course at any time if the prerequisites are met.
//Any number of courses can be taken at the same time.
//Return the minimum number of months needed to complete all the courses.
//Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).


/**
 * @param {number} n
 * @param {number[][]} relations
 * @param {number[]} time
 * @return {number}
 */
var minimumTime = function(n, relations, time) {
    let graph = new Map();
    for (let i = 0; i < n; i++) {
        graph.set(i, []);
    }
    for (let i = 0; i < relations.length; i++) {
        let [prev, next] = relations[i];
        graph.get(prev).push(next);
    }
    let dp = new Array(n).fill(0);
    let visited = new Array(n).fill(false);
    let result = 0;
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            let max = dfs(i, graph, time, dp, visited);
            result = Math.max(result, max);
        }
    }
    return result;
    
    
};

    