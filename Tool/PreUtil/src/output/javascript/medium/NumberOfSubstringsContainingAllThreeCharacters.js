/**https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ */
//Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.


/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    let result = 0;
    let left = 0;
    let right = 0;
    let map = new Map();
    while(right < s.length){
        if(map.has(s[right])){
            map.set(s[right], map.get(s[right]) + 1);
        }else{
            map.set(s[right], 1);
        }
        while(map.size == 3){
            result += s.length - right;
            if(map.get(s[left]) == 1){
                map.delete(s[left]);
            }else{
                map.set(s[left], map.get(s[left]) - 1);
            }
            left++;
        }
        right++;
    }
    return result;
    
};

    