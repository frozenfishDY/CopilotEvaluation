/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.


class DecodeString {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();
        StringBuilder currStr = new StringBuilder();
        int k = 0;
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                k = k * 10 + c - '0';
            }else if(c == '['){
                countStack.push(k);
                strStack.push(currStr);
                currStr = new StringBuilder();
                k = 0;
            }else if(c == ']'){
                StringBuilder temp = currStr;
                currStr = strStack.pop();
                for(k = countStack.pop(); k > 0; k--){
                    currStr.append(temp);
                }
            }else{
                currStr.append(c);
            }
        }
        return currStr.toString();
        
    }
}

    