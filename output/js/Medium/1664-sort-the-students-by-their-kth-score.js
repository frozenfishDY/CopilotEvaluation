/**https://leetcode.com/problems/sort-the-students-by-their-kth-score/ */
//There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
//You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.
//Return the matrix after sorting it.


/**
 * @param {number[][]} score
 * @param {number} k
 * @return {number[][]}
 */
var sortTheStudents = function(score, k) {
    let m = score.length;
    let n = score[0].length;
    let map = new Map();
    for(let i = 0; i < m; i++){
        let key = score[i][k];
        if(map.has(key)){
            map.get(key).push(i);
        }else{
            map.set(key, [i]);
        }
    }
    let keys = Array.from(map.keys()).sort((a, b) => b - a);
    let result = [];
    for(let i = 0; i < keys.length; i++){
        let students = map.get(keys[i]);
        for(let j = 0; j < students.length; j++){
            result.push(score[students[j]]);
        }
    }
    return result;
    
};

    