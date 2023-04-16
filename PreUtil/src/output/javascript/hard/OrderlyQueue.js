/**https://leetcode.com/problems/orderly-queue/ */
//You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..
//Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.


/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function(s, k) {
    if(k === 1){
        let result = s;
        for(let i = 0; i < s.length; i++){
            let temp = s.substring(i) + s.substring(0, i);
            if(temp < result){
                result = temp;
            }
        }
        return result;
    }else{
        let arr = s.split("");
        arr.sort();
        return arr.join("");
    }
    
};

    