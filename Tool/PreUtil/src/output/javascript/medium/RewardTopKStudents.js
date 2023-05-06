/**https://leetcode.com/problems/reward-top-k-students/ */
//You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.
//Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.
//You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.
//Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.


/**
 * @param {string[]} positive_feedback
 * @param {string[]} negative_feedback
 * @param {string[]} report
 * @param {number[]} student_id
 * @param {number} k
 * @return {number[]}
 */
var topStudents = function(positive_feedback, negative_feedback, report, student_id, k) {
    let n = report.length;
    let m = student_id.length;
    let p = positive_feedback.length;
    let q = negative_feedback.length;
    let points = new Array(m).fill(0);
    let idToIndex = new Map();
    for(let i = 0; i < m; i++){
        idToIndex.set(student_id[i], i);
    }
    for(let i = 0; i < n; i++){
        let id = student_id[i];
        let index = idToIndex.get(id);
        let words = report[i].split(" ");
        for(let word of words){
            if(positive_feedback.includes(word)){
                points[index] += 3;
            }else if(negative_feedback.includes(word)){
                points[index] -= 1;
            }
        }
    }
    let ans = [];
    let maxHeap = new MaxHeap();
    for(let i = 0; i < m; i++){
        maxHeap.add([points[i], student_id[i]]);
    }
    for(let i = 0; i < k; i++){
        ans.push(maxHeap.poll()[1]);
    }
    return ans;
    
    
};

    