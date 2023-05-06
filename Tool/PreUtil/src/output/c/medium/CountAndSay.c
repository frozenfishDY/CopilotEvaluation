/**https://leetcode.com/problems/count-and-say/ */
//The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//countAndSay(1) = "1"
//countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
//To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
//For example, the saying and conversion for digit string "3322251":
// 


char * countAndSay(int n){
    char *result = (char*)malloc(sizeof(char)*1000);
    char *temp = (char*)malloc(sizeof(char)*1000);
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    if(n == 1){
        result[0] = '1';
        result[1] = '\0';
        return result;
    }
    result = countAndSay(n-1);
    while(result[i] != '\0'){
        count = 1;
        while(result[i] == result[i+1]){
            count++;
            i++;
        }
        temp[j] = count + '0';
        temp[j+1] = result[i];
        j = j + 2;
        i++;
    }
    temp[j] = '\0';
    return temp;

}

    