/**https://leetcode.com/problems/integer-to-roman/ */
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
//Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//I can be placed before V (5) and X (10) to make 4 and 9. 
//X can be placed before L (50) and C (100) to make 40 and 90. 
//C can be placed before D (500) and M (1000) to make 400 and 900.
//Given an integer, convert it to a roman numeral.


char * intToRoman(int num){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = 0;
    int count = 0;
    char* result = NULL;
    char* roman = "IVXLCDM";
    int value[7] = {1, 5, 10, 50, 100, 500, 1000};
    for(i = 6; i >= 0; i--){
        count = num / value[i];
        num = num % value[i];
        if(count == 0){
            continue;
        }
        if(count == 4){
            if(i % 2 == 0){
                len += 2;
            }
            else{
                len += 3;
            }
        }
        else{
            len += count;
        }
    }
    result = (char*)malloc(sizeof(char) * (len + 1));
    for(i = 6; i >= 0; i--){
        count = num / value[i];
        num = num % value[i];
        if(count == 0){
            continue;
        }
        if(count == 4){
            if(i % 2 == 0){
                result[k++] = roman[i];
                result[k++] = roman[i + 1];
            }
            else{
                result[k++] = roman[i - 1];
                result[k++] = roman[i + 1];
            }
        }
        else{
            for(j = 0; j < count; j++){
                result[k++] = roman[i];
            }
        }
    }
    result[k] = '\0';
    return result;

}

    