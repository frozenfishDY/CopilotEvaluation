/**https://leetcode.com/problems/first-unique-character-in-a-string/ */
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    let map = {};
    for(let i = 0; i < s.length; i++){
        if(map[s[i]] == undefined){
            map[s[i]] = 1;
        }else{
            map[s[i]]++;
        }
    }
    for(let i = 0; i < s.length; i++){
        if(map[s[i]] == 1){
            return i;
        }
    }
    return -1;
    
};

    