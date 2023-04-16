/**https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/ */
//Given a string s, determine if it is valid.
//A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
//Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
//Return true if s is a valid string, otherwise, return false.


/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    for(let i = 0; i < s.length; i++){
        if(s[i] == 'a'){
            stack.push('a');
        }else if(s[i] == 'b'){
            if(stack.length == 0 || stack[stack.length - 1] != 'a'){
                return false;
            }
            stack.push('b');
        }else{
            if(stack.length < 2 || stack[stack.length - 1] != 'b' || stack[stack.length - 2] != 'a'){
                return false;
            }
            stack.pop();
            stack.pop();
        }
    }
    return stack.length == 0;    

};

    