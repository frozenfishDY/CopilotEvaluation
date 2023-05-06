/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.


/**
 * @param {string} s
 * @return {string[]}
 */
var maxNumOfSubstrings = function(s) {
    let n = s.length;
    let left = new Array(26).fill(n);
    let right = new Array(26).fill(0);
    for(let i = 0; i < n; i++){
        let idx = s.charCodeAt(i) - 97;
        left[idx] = Math.min(left[idx], i);
        right[idx] = Math.max(right[idx], i);
    }
    let res = [];
    let l = 0;
    let r = 0;
    for(let i = 0; i < n; i++){
        if(i == left[s.charCodeAt(i) - 97]){
            let l = i;
            let r = right[s.charCodeAt(i) - 97];
            for(let j = l; j <= r; j++){
                if(left[s.charCodeAt(j) - 97] < l){
                    l = left[s.charCodeAt(j) - 97];
                    j = l;
                }
                else if(right[s.charCodeAt(j) - 97] > r){
                    r = right[s.charCodeAt(j) - 97];
                    j = l;
                }
            }
            res.push(s.substring(l, r + 1));
            i = r;
        }
    }
    return res;
    
};

    