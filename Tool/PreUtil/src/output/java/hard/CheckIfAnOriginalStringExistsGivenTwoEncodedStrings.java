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


class CheckIfAnOriginalStringExistsGivenTwoEncodedStrings {
    public boolean possiblyEquals(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i++;
                j++;
            } else if (Character.isDigit(s1.charAt(i)) && Character.isDigit(s2.charAt(j))) {
                int num1 = 0;
                int num2 = 0;
                while (i < n1 && Character.isDigit(s1.charAt(i))) {
                    num1 = num1 * 10 + (s1.charAt(i) - '0');
                    i++;
                }
                while (j < n2 && Character.isDigit(s2.charAt(j))) {
                    num2 = num2 * 10 + (s2.charAt(j) - '0');
                    j++;
                }
                if (num1 != num2) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return i == n1 && j == n2;
        
    }
}
     
    