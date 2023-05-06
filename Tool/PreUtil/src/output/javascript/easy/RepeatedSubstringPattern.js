/**https://leetcode.com/problems/repeated-substring-pattern/ */
//Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.


/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function(s) {
    let len = s.length;
    for(let i = 1; i <= len / 2; i++){
        if(len % i == 0){
            let sub = s.substring(0, i);
            let j = i;
            while(j < len){
                if(s.substring(j, j + i) != sub){
                    break;
                }
                j += i;
            }
            if(j == len){
                return true;
            }
        }
    }
    return false;
    
};

    