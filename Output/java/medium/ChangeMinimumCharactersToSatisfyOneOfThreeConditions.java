/**https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/ */
//You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
//Your goal is to satisfy one of the following three conditions:
//Every letter in a is strictly less than every letter in b in the alphabet.
//Every letter in b is strictly less than every letter in a in the alphabet.
//Both a and b consist of only one distinct letter.
//Return the minimum number of operations needed to achieve your goal.


class ChangeMinimumCharactersToSatisfyOneOfThreeConditions {
    public int minCharacters(String a, String b) {
        int[] countA = new int[26];
        int[] countB = new int[26];
        for(int i = 0; i < a.length(); i++){
            countA[a.charAt(i) - 'a']++;
        }
        for(int i = 0; i < b.length(); i++){
            countB[b.charAt(i) - 'a']++;
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < 26; i++){
            int temp = 0;
            for(int j = 0; j < 26; j++){
                if(j < i){
                    temp += countA[j] + countB[j];
                }
                else if(j > i){
                    temp += countA[j] + countB[j];
                }
            }
            ans = Math.min(ans, temp);
        }
        for(int i = 0; i < 26; i++){
            int temp = 0;
            for(int j = 0; j < 26; j++){
                if(j < i){
                    temp += countA[j];
                }
                else if(j > i){
                    temp += countB[j];
                }
            }
            ans = Math.min(ans, temp);
        }
        for(int i = 0; i < 26; i++){
            int temp = 0;
            for(int j = 0; j < 26; j++){
                if(j < i){
                    temp += countB[j];
                }
                else if(j > i){
                    temp += countA[j];
                }
            }
            ans = Math.min(ans, temp);
        }
        return ans;
        
    }
}
     
    