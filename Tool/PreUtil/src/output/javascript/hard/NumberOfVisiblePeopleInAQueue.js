/**https://leetcode.com/problems/number-of-visible-people-in-a-queue/ */
//There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.
//A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
//Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.


/**
 * @param {number[]} heights
 * @return {number[]}
 */
var canSeePersonsCount = function(heights) {
    let result = new Array(heights.length).fill(0);
    let stack = [];
    for (let i = heights.length - 1; i >= 0; i--) {
        while (stack.length > 0 && heights[i] > heights[stack[stack.length - 1]]) {
            result[i]++;
            result[stack[stack.length - 1]]++;
            stack.pop();
        }
        stack.push(i);
    }
    return result;
    
};

    