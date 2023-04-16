/**https://leetcode.com/problems/queue-reconstruction-by-height/ */
//You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
//Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).


/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
    people.sort((a, b) => {
        if(a[0] === b[0]){
            return a[1] - b[1];
        }else{
            return b[0] - a[0];
        }
    });
    let result = [];
    for(let i = 0; i < people.length; i++){
        let [h, k] = people[i];
        result.splice(k, 0, people[i]);
    }
    return result;
    
};

    