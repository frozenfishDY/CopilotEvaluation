/**https://leetcode.com/problems/rabbits-in-forest/ */
//There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
//Given the array answers, return the minimum number of rabbits that could be in the forest.


/**
 * @param {number[]} answers
 * @return {number}
 */
var numRabbits = function(answers) {
    let map = new Map();
    let result = 0;
    for(let i = 0; i < answers.length; i++){
        if(map.has(answers[i])){
            map.set(answers[i], map.get(answers[i]) + 1);
        }else{
            map.set(answers[i], 1);
        }
    }
    for(let [key, value] of map){
        result += Math.ceil(value / (key + 1)) * (key + 1);
    }
    return result;
    
};

    