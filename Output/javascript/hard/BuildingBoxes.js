/**https://leetcode.com/problems/building-boxes/ */
//You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:
//You can place the boxes anywhere on the floor.
//If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
//Given an integer n, return the minimum possible number of boxes touching the floor.


/**
 * @param {number} n
 * @return {number}
 */
var minimumBoxes = function(n) {
    let dp = new Array(n + 1).fill(0);
    let i = 1;
    let sum = 0;
    while(sum < n){
        sum += i;
        dp[i] = sum;
        i++;
    }
    let res = i - 1;
    let j = i - 2;
    while(sum > n){
        sum -= j;
        j--;
        res++;
    }
    return res;
    
};

    