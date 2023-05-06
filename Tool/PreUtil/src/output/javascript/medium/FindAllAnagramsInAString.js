/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    let n = s.length;
    let m = p.length;
    let result = [];
    if(n < m){
        return result;
    }
    let pMap = new Map();
    let sMap = new Map();
    for(let i = 0; i < m; i++){
        let pChar = p[i];
        let sChar = s[i];
        if(pMap.has(pChar)){
            pMap.set(pChar, pMap.get(pChar) + 1);
        }else{
            pMap.set(pChar, 1);
        }
        if(sMap.has(sChar)){
            sMap.set(sChar, sMap.get(sChar) + 1);
        }else{
            sMap.set(sChar, 1);
        }
    }
    if(isEqual(pMap, sMap)){
        result.push(0);
    }
    for(let i = m; i < n; i++){
        let sChar = s[i];
        let sPrevChar = s[i - m];
        if(sMap.has(sChar)){
            sMap.set(sChar, sMap.get(sChar) + 1);
        }else{
            sMap.set(sChar, 1);
        }
        if(sMap.get(sPrevChar) == 1){
            sMap.delete(sPrevChar);
        }else{
            sMap.set(sPrevChar, sMap.get(sPrevChar) - 1);
        }
        if(isEqual(pMap, sMap)){
            result.push(i - m + 1);
        }
    }
    return result;
    
    
    
};

    