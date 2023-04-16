/**https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/ */
//A happy string is a string that:
//consists only of letters of the set ['a', 'b', 'c'].
//s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
//For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
//Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
//Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


class TheKThLexicographicalStringOfAllHappyStringsOfLengthN {
    public String getHappyString(int n, int k) {
        int total = (int)Math.pow(2, n - 1);
        if(k > 3 * total){
            return "";
        }
        int index = (k - 1) / total;
        char[] chars = new char[n];
        chars[0] = (char)('a' + index);
        int count = 1;
        while(count < n){
            int temp = (k - 1) % total;
            index = temp / (total / 2);
            chars[count] = (char)('a' + index);
            count++;
            total /= 2;
        }
        return new String(chars);
        
    }
}

    