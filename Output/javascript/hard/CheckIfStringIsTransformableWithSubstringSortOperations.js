/**https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/ */
//Given two strings s and t, transform string s into string t using the following operation any number of times:
//Choose a non-empty substring in s and sort it in place so the characters are in ascending order.
//For example, applying the operation on the underlined substring in "14234" results in "12344".
//Return true if it is possible to transform s into t. Otherwise, return false.
//A substring is a contiguous sequence of characters within a string.


/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isTransformable = function(s, t) {
    let n = s.length;
    let m = t.length;
    if(n != m){
        return false;
    }
    let pos = new Array(10);
    for(let i = 0; i < 10; i++){
        pos[i] = [];
    }
    for(let i = 0; i < n; i++){
        let idx = s.charCodeAt(i) - 48;
        pos[idx].push(i);
    }
    for(let i = 0; i < n; i++){
        let idx = t.charCodeAt(i) - 48;
        if(pos[idx].length == 0){
            return false;
        }
        for(let j = 0; j < idx; j++){
            if(pos[j].length > 0 && pos[j][0] < pos[idx][0]){
                return false;
            }
        }
        pos[idx].shift();
    }
    return true;
    
};

    