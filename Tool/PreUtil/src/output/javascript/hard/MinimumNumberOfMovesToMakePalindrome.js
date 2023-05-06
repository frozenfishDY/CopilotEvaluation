/**https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/ */
//You are given a string s consisting only of lowercase English letters.
//In one move, you can select any two adjacent characters of s and swap them.
//Return the minimum number of moves needed to make s a palindrome.
//Note that the input will be generated such that s can always be converted to a palindrome.


/**
 * @param {string} s
 * @return {number}
 */
var minMovesToMakePalindrome = function(s) {
    let n = s.length;
    let count = new Array(26).fill(0);
    for(let i = 0; i < n; i++){
        count[s[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    let odd = 0;
    for(let i = 0; i < 26; i++){
        if(count[i] % 2 == 1){
            odd++;
        }
    }
    if(odd == 0){
        return 0;
    }
    let ans = 0;
    let i = 0;
    let j = n - 1;
    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            let k = j - 1;
            while(k > i && s[k] != s[i]){
                k--;
            }
            if(k == i){
                return -1;
            }
            for(let l = k; l < j; l++){
                [s[l], s[l + 1]] = [s[l + 1], s[l]];
                ans++;
            }
            i++;
            j--;
        }
    }
    return ans;
    
};

    