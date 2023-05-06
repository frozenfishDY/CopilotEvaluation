/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.


/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var isItPossible = function(word1, word2) {
    let n = word1.length;
    let m = word2.length;
    if(n != m){
        return false;
    }
    let count = 0;
    let map = new Map();
    for(let i = 0; i < n; i++){
        if(word1[i] != word2[i]){
            count++;
            if(map.has(word1[i])){
                map.set(word1[i], map.get(word1[i]) + 1);
            }
            else{
                map.set(word1[i], 1);
            }
            if(map.has(word2[i])){
                map.set(word2[i], map.get(word2[i]) + 1);
            }
            else{
                map.set(word2[i], 1);
            }
        }
    }
    if(count == 2){
        for(let [key, value] of map){
            if(value == 2){
                return true;
            }
        }
    }
    return false;
    
};

    