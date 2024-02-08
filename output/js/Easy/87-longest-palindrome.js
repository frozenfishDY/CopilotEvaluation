/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome here.


/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let map = {};
    for(let i = 0; i < s.length; i++){
        if(map[s[i]] == undefined){
            map[s[i]] = 1;
        }else{
            map[s[i]]++;
        }
    }
    let count = 0;
    let flag = false;
    for(let key in map){
        if(map[key]%2 == 0){
            count += map[key];
        }else{
            flag = true;
            count += map[key] - 1;
        }
    }
    if(flag){
        count++;
    }
    return count;
    
};

    