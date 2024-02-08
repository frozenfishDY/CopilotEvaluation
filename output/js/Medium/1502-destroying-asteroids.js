/**https://leetcode.com/problems/destroying-asteroids/ */
//You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.
//You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.
//Return true if all asteroids can be destroyed. Otherwise, return false.


/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
var asteroidsDestroyed = function(mass, asteroids) {
    let stack = [];
    for (let i = 0; i < asteroids.length; i++) {
        if (mass >= asteroids[i]) {
            mass += asteroids[i];
        } else {
            stack.push(asteroids[i]);
        }
    }
    while (stack.length > 0) {
        let cur = stack.pop();
        if (mass >= cur) {
            mass += cur;
        } else {
            return false;
        }
    }
    return true;
    
};

    