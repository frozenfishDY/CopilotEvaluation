/**https://leetcode.com/problems/isomorphic-strings/ */
//Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    let map = new Map();
    let set = new Set();
    for(let i = 0; i < s.length; i++){
        let c1 = s[i];
        let c2 = t[i];
        if(map.has(c1)){
            if(map.get(c1) != c2){
                return false;
            }
        }else{
            if(set.has(c2)){
                return false;
            }
            map.set(c1, c2);
            set.add(c2);
        }
    }
    return true;
    
};

    