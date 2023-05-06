/**https://leetcode.com/problems/course-schedule/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return true if you can finish all courses. Otherwise, return false.


/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    let graph = new Array(numCourses).fill(0).map(() => new Array());
    let inDegree = new Array(numCourses).fill(0);
    for(let i = 0; i < prerequisites.length; i++){
        let course = prerequisites[i][0];
        let pre = prerequisites[i][1];
        graph[pre].push(course);
        inDegree[course]++;
    }
    let queue = [];
    for(let i = 0; i < inDegree.length; i++){
        if(inDegree[i] == 0){
            queue.push(i);
        }
    }
    while(queue.length > 0){
        let course = queue.shift();
        for(let i = 0; i < graph[course].length; i++){
            let nextCourse = graph[course][i];
            inDegree[nextCourse]--;
            if(inDegree[nextCourse] == 0){
                queue.push(nextCourse);
            }
        }
    }
    for(let i = 0; i < inDegree.length; i++){
        if(inDegree[i] != 0){
            return false;
        }
    }
    return true;
    
};

    