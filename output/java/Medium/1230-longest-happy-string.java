/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//s only contains the letters 'a', 'b', and 'c'.
//s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//s contains at most a occurrences of the letter 'a'.
//s contains at most b occurrences of the letter 'b'.
//s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.


class LongestHappyString {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder sb = new StringBuilder();
        int[] count = new int[]{a, b, c};
        int[] last = new int[]{0, 0, 0};
        while(count[0] > 0 || count[1] > 0 || count[2] > 0){
            int max = 0;
            int index = 0;
            for(int i = 0; i < 3; i++){
                if(count[i] > max && last[i] != 2){
                    max = count[i];
                    index = i;
                }
            }
            if(max == 0){
                break;
            }
            sb.append((char)('a' + index));
            count[index]--;
            last[index]++;
            last[(index + 1) % 3] = 0;
            last[(index + 2) % 3] = 0;
        }
        return sb.toString();
        
        
    }
}

    