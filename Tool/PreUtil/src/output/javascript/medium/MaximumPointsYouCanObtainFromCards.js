/**https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ */
//There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
//In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
//Your score is the sum of the points of the cards you have taken.
//Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(cardPoints, k) {
    let sum = 0;
    for (let i = 0; i < k; i++) {
        sum += cardPoints[i];
    }
    let max = sum;
    for (let i = 0; i < k; i++) {
        sum -= cardPoints[k - 1 - i];
        sum += cardPoints[cardPoints.length - 1 - i];
        max = Math.max(max, sum);
    }
    return max;
    
};

    