/**https://leetcode.com/problems/additive-number/ */
//An additive number is a string whose digits can form an additive sequence.
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//Given a string containing only digits, return true if it is an additive number or false otherwise.
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.


bool isAdditiveNumber(char * num){
    int len = strlen(num);
    for(int i = 1; i <= len / 2; i++){
        for(int j = 1; j <= (len - i) / 2; j++){
            if(isValid(i, j, num)){
                return true;
            }
        }
    }
    return false;

}

    