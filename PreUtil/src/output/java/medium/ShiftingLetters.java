/**https://leetcode.com/problems/shifting-letters/ */
//You are given a string s of lowercase English letters and an integer array shifts of the same length.
//Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
//For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
//Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
//Return the final string after all such shifts to s are applied.


class ShiftingLetters {
    public String shiftingLetters(String s, int[] shifts) {
        int n = s.length();
        long[] sum = new long[n];
        sum[n - 1] = shifts[n - 1];
        for(int i = n - 2; i >= 0; i--){
            sum[i] = sum[i + 1] + shifts[i];
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            int shift = (int)(sum[i] % 26);
            char c = (char)((s.charAt(i) - 'a' + shift) % 26 + 'a');
            sb.append(c);
        }
        return sb.toString();
        
        
    }
}

    