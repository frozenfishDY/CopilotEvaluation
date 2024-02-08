/**https://leetcode.com/problems/minimum-window-substring/ */
//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//The testcases will be generated such that the answer is unique.


/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let map = new Map();
    for(let i = 0; i < t.length; i++){
        if(map.has(t[i])){
            map.set(t[i], map.get(t[i]) + 1);
        }else{
            map.set(t[i], 1);
        }
    }
    let count = map.size;
    let left = 0;
    let right = 0;
    let min = Number.MAX_SAFE_INTEGER;
    let result = "";
    while(right < s.length){
        if(map.has(s[right])){
            map.set(s[right], map.get(s[right]) - 1);
            if(map.get(s[right]) === 0){
                count--;
            }
        }
        while(count === 0){
            if(right - left + 1 < min){
                min = right - left + 1;
                result = s.substring(left, right + 1);
            }
            if(map.has(s[left])){
                map.set(s[left], map.get(s[left]) + 1);
                if(map.get(s[left]) > 0){
                    count++;
                }
            }
            left++;
        }
        right++;
    }
    return result;
    
};

    