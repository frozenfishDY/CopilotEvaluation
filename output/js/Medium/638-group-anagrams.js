/**https://leetcode.com/problems/group-anagrams/ */
//Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let result = [];
    if(strs.length == 0){
        return result;
    }
    let map = new Map();
    for(let i = 0; i < strs.length; i++){
        let sorted = strs[i].split("").sort().join("");
        if(map.has(sorted)){
            let list = map.get(sorted);
            list.push(strs[i]);
            map.set(sorted, list);
        }else{
            let list = [];
            list.push(strs[i]);
            map.set(sorted, list);
        }
    }
    for(let list of map.values()){
        result.push(list);
    }
    return result;
    
};

    