/**https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/ */
//An original string, consisting of lowercase English letters, can be encoded by the following steps:
//Arbitrarily split it into a sequence of some number of non-empty substrings.
//Arbitrarily choose some elements (possibly none) of the sequence, and replace each with its length (as a numeric string).
//Concatenate the sequence as the encoded string.
//For example, one way to encode an original string "abcdefghijklmnop" might be:
//Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
//Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes ["ab", "12", "1", "p"].
//Concatenate the elements of the sequence to get the encoded string: "ab121p".
//Given two encoded strings s1 and s2, consisting of lowercase English letters and digits 1-9 (inclusive), return true if there exists an original string that could be encoded as both s1 and s2. Otherwise, return false.
//Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.


/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var possiblyEquals = function(s1, s2) {
    let n1 = s1.length;
    let n2 = s2.length;
    let i = 0;
    let j = 0;
    while(i < n1 && j < n2){
        let count1 = 0;
        while(i < n1 && s1[i] >= '0' && s1[i] <= '9'){
            count1 = count1 * 10 + (s1[i] - '0');
            i++;
        }
        let count2 = 0;
        while(j < n2 && s2[j] >= '0' && s2[j] <= '9'){
            count2 = count2 * 10 + (s2[j] - '0');
            j++;
        }
        if(count1 != count2){
            return false;
        }
    }
    return i == n1 && j == n2;
    
};

    