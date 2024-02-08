/**https://leetcode.com/problems/maximize-distance-to-closest-person/ */
//You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//There is at least one empty seat, and at least one person sitting.
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//Return that maximum distance to the closest person.


/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
    let max = 0;
    let left = 0;
    let right = 0;
    let count = 0;
    while(right < seats.length){
        while(seats[right] == 1){
            count--;
            left++;
        }
        count++;
        max = Math.max(max, count);
        right++;
    }
    return max;
    
};

    