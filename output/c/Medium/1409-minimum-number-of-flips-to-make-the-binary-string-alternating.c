/**https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/ */
//You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
//	Type-1: Remove the character at the start of the string s and append it to the end of the string.
//	Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
//Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
//The string is called alternating if no two adjacent characters are equal.
//	For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
// 
//Example 1:
//Input: s = "111000"
//Output: 2
//Explanation: Use the first operation two times to make s = "100011".
//Then, use the second operation on the third and sixth elements to make s = "101010".
//Example 2:
//Input: s = "010"
//Output: 0
//Explanation: The string is already alternating.
//Example 3:
//Input: s = "1110"
//Output: 1
//Explanation: Use the second operation on the second element to make s = "1010".
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either '0' or '1'.
int minFlips(char * s){
int len=strlen(s);
    int i;
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    for(i=0;i<len;i++){
        if(i%2==0&&s[i]=='1'){
            count1++;
        }else if(i%2==0&&s[i]=='0'){
            count2++;
        }else if(i%2==1&&s[i]=='0'){
            count3++;
        }else if(i%2==1&&s[i]=='1'){
            count4++;
        }
    }
    if(len%2==0){
        if(count1+count3<count2+count4){
            return count1+count3;
        }else{
            return count2+count4;
        }
    }else{
        if(count1+count3<count2+count4){
            return count2+count3;
        }else{
            return count1+count4;
        }
    }
}