/**https://leetcode.com/problems/car-fleet-ii/ */
//There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:
//positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
//speedi is the initial speed of the ith car in meters per second.
//For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.
//Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.


/**
 * @param {number[][]} cars
 * @return {number[]}
 */
var getCollisionTimes = function(cars) {
    let n = cars.length;
    let ans = new Array(n).fill(-1);
    let stack = [];
    for(let i = n - 1; i >= 0; i--){
        let [pos, speed] = cars[i];
        while(stack.length > 0){
            let [pos2, speed2, time] = stack[stack.length - 1];
            if(speed <= speed2 || (time > 0 && (pos2 - pos) / (speed - speed2) >= time)){
                stack.pop();
            }else{
                break;
            }
        }
        if(stack.length > 0){
            let [pos2, speed2, time] = stack[stack.length - 1];
            ans[i] = (pos2 - pos) / (speed - speed2);
        }
        stack.push([pos, speed, ans[i]]);
    }
    return ans;
    
};

    