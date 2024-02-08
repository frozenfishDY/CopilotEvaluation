/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length != t.length){
        return false;
    }
    let map = {};
    for(let i = 0; i < s.length; i++){
        if(map[s[i]] == undefined){
            map[s[i]] = 1;
        }else{
            map[s[i]]++;
        }
    }
    for(let i = 0; i < t.length; i++){
        if(map[t[i]] == undefined){
            return false;
        }else{
            map[t[i]]--;
        }
    }
    for(let key in map){
        if(map[key] != 0){
            return false;
        }
    }
    return true;
    
};

    