/**https://leetcode.com/problems/top-k-frequent-words/ */
//Given an array of strings words and an integer k, return the k most frequent strings.
//Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.


/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */
var topKFrequent = function(words, k) {
    let map = new Map();
    for(let i = 0; i < words.length; i++){
        if(map.has(words[i])){
            map.set(words[i], map.get(words[i]) + 1);
        }else{
            map.set(words[i], 1);
        }
    }
    let arr = [];
    for(let [key, value] of map){
        arr.push([key, value]);
    }
    arr.sort((a, b) => {
        if(a[1] == b[1]){
            return a[0].localeCompare(b[0]);
        }else{
            return b[1] - a[1];
        }
    });
    let result = [];
    for(let i = 0; i < k; i++){
        result.push(arr[i][0]);
    }
    return result;
    
};

    