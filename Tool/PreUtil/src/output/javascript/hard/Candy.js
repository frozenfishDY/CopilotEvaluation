/**https://leetcode.com/problems/candy/ */
//There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
//You are giving candies to these children subjected to the following requirements:
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute the candies to the children.


/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
    let n = ratings.length;
    let left = [];
    for(let i = 0; i < n; i++){
        left.push(1);
    }
    for(let i = 1; i < n; i++){
        if(ratings[i] > ratings[i - 1]){
            left[i] = left[i - 1] + 1;
        }
    }
    let right = [];
    for(let i = 0; i < n; i++){
        right.push(1);
    }
    for(let i = n - 2; i >= 0; i--){
        if(ratings[i] > ratings[i + 1]){
            right[i] = right[i + 1] + 1;
        }
    }
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += Math.max(left[i], right[i]);
    }
    return sum;
    
};

    