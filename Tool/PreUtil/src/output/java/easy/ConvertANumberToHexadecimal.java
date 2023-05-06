/**https://leetcode.com/problems/convert-a-number-to-hexadecimal/ */
//Given an integer num, return a string representing its hexadecimal representation. For negative integers, two��s complement method is used.
//All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
//Note: You are not allowed to use any built-in library method to directly solve this problem.


class ConvertANumberToHexadecimal {
    public String toHex(int num) {
        if(num == 0) return "0";
        char[] hex = new char[8];
        int index = 7;
        while(num != 0){
            int digit = num & 15;
            if(digit < 10){
                hex[index--] = (char)(digit + '0');
            }else{
                hex[index--] = (char)(digit - 10 + 'a');
            }
            num = num >>> 4;
        }
        return new String(hex, index + 1, 8 - index - 1);
        
    }
}

    