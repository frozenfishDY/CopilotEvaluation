/**https://leetcode.com/problems/friends-of-appropriate-ages/ */
//There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
//A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
//age[y] <= 0.5 * age[x] + 7
//age[y] > age[x]
//age[y] > 100 && age[x] < 100
//Otherwise, x will send a friend request to y.
//Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
//Return the total number of friend requests made.


/**
 * @param {number[]} ages
 * @return {number}
 */
var numFriendRequests = function(ages) {
    let result = 0;
    let count = new Array(121).fill(0);
    for(let i = 0; i < ages.length; i++){
        count[ages[i]]++;
    }
    for(let i = 15; i <= 120; i++){
        for(let j = 15; j <= 120; j++){
            if(i * 0.5 + 7 >= j){
                continue;
            }
            if(i < j){
                continue;
            }
            if(i < 100 && j > 100){
                continue;
            }
            result += count[i] * (count[j] - (i == j ? 1 : 0));
        }
    }
    return result;
    
};

    