/**https://leetcode.com/problems/sort-characters-by-frequency/ */
//Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
//Return the sorted string. If there are multiple answers, return any of them.


/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    let map = new Map();
    for(let i = 0; i < s.length; i++){
        let count = map.get(s[i]) || 0;
        map.set(s[i], count + 1);
    }
    let arr = [];
    for(let [key, value] of map){
        arr.push([key, value]);
    }
    arr.sort((a, b) => b[1] - a[1]);
    let result = "";
    for(let i = 0; i < arr.length; i++){
        result += arr[i][0].repeat(arr[i][1]);
    }
    return result;
    
};

    