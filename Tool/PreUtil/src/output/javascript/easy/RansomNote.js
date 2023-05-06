/**https://leetcode.com/problems/ransom-note/ */
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.


/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    let map = {};
    for(let i = 0; i < magazine.length; i++){
        if(map[magazine[i]] == undefined){
            map[magazine[i]] = 1;
        }else{
            map[magazine[i]]++;
        }
    }
    for(let i = 0; i < ransomNote.length; i++){
        if(map[ransomNote[i]] == undefined){
            return false;
        }else{
            map[ransomNote[i]]--;
        }
    }
    return true;
    
};

    