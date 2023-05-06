/**https://leetcode.com/problems/course-schedule-ii/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function(numCourses, prerequisites) {
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
    let result = [];
    while(queue.length > 0){
        let course = queue.shift();
        result.push(course);
        for(let i = 0; i < graph[course].length; i++){
            let nextCourse = graph[course][i];
            inDegree[nextCourse]--;
            if(inDegree[nextCourse] == 0){
                queue.push(nextCourse);
            }
        }
    }
    if(result.length != numCourses){
        return [];
    }
    return result;
    
};

    