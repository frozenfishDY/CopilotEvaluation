/**https://leetcode.com/problems/parallel-courses-ii/ */
//You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.
//In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.
//Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.


/**
 * @param {number} n
 * @param {number[][]} relations
 * @param {number} k
 * @return {number}
 */
var minNumberOfSemesters = function(n, relations, k) {
    let graph = new Array(n).fill(0).map(() => new Array(n).fill(0));
    let indegree = new Array(n).fill(0);
    for(let i = 0; i < relations.length; i++){
        let [u, v] = relations[i];
        graph[u - 1][v - 1] = 1;
        indegree[v - 1]++;
    }
    let q = new Queue();
    for(let i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    let ans = 0;
    while(!q.isEmpty()){
        let size = Math.min(q.size(), k);
        for(let i = 0; i < size; i++){
            let cur = q.pop();
            for(let j = 0; j < n; j++){
                if(graph[cur][j] == 1){
                    indegree[j]--;
                    if(indegree[j] == 0){
                        q.push(j);
                    }
                }
            }
        }
        ans++;
    }
    return ans;
    
    
};

    