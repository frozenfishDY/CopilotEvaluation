/**https://leetcode.com/problems/word-subsets/ */
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1. You may return the answer in any order.


/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function(words1, words2) {
    let result = [];
    let map = {};
    for(let i = 0; i < words2.length; i++){
        let word = words2[i];
        let temp = {};
        for(let j = 0; j < word.length; j++){
            temp[word[j]] = (temp[word[j]] || 0) + 1;
        }
        for(let key in temp){
            map[key] = Math.max(map[key] || 0, temp[key]);
        }
    }
    for(let i = 0; i < words1.length; i++){
        let word = words1[i];
        let temp = {};
        for(let j = 0; j < word.length; j++){
            temp[word[j]] = (temp[word[j]] || 0) + 1;
        }
        let flag = true;
        for(let key in map){
            if(map[key] > temp[key]){
                flag = false;
                break;
            }
        }
        if(flag){
            result.push(word);
        }
    }
    return result;
    
};

    