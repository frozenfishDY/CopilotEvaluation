/**https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/ */
//A happy string is a string that:
//consists only of letters of the set ['a', 'b', 'c'].
//s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
//For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
//Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
//Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getHappyString = function(n, k) {
    let arr = ['a', 'b', 'c'];
    let res = [];
    let count = 0;
    let dfs = (str) => {
        if (str.length === n) {
            res.push(str);
            count++;
            return;
        }
        for (let i = 0; i < arr.length; i++) {
            if (str.length === 0 || arr[i] !== str[str.length - 1]) {
                dfs(str + arr[i]);
            }
        }
    }
    dfs('');
    return res[k - 1] || '';
    
};

    