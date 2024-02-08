/**https://leetcode.com/problems/stone-game-vi/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//There are n stones in a pile. On each player's turn, they can remove a stone from the pile and receive points based on the stone's value. Alice and Bob may value the stones differently.
//You are given two integer arrays of length n, aliceValues and bobValues. Each aliceValues[i] and bobValues[i] represents how Alice and Bob, respectively, value the ith stone.
//The winner is the person with the most points after all the stones are chosen. If both players have the same amount of points, the game results in a draw. Both players will play optimally. Both players know the other's values.
//Determine the result of the game, and:
//If Alice wins, return 1.
//If Bob wins, return -1.
//If the game results in a draw, return 0.


/**
 * @param {number[]} aliceValues
 * @param {number[]} bobValues
 * @return {number}
 */
var stoneGameVI = function(aliceValues, bobValues) {
    let n = aliceValues.length;
    let sum = 0;
    let alice = 0;
    let bob = 0;
    let arr = [];
    for (let i = 0; i < n; i++) {
        arr.push([aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]]);
    }
    arr.sort((a, b) => b[0] - a[0]);
    for (let i = 0; i < n; i++) {
        if (i % 2 == 0) {
            alice += arr[i][1];
        } else {
            bob += arr[i][2];
        }
    }
    if (alice > bob) {
        return 1;
    } else if (alice < bob) {
        return -1;
    } else {
        return 0;
    }
    
};

    