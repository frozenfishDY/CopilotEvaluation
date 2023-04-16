/**https://leetcode.com/problems/zigzag-conversion/ */
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//string convert(string s, int numRows);


char * convert(char * s, int numRows){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(s);
    int flag = 0;
    int count = 0;
    int max = 0;
    char* result = NULL;
    if(numRows == 1){
        return s;
    }
    for(i = 0; i < numRows; i++){
        for(j = i; j < len; j += (2 * numRows - 2)){
            if(i == 0 || i == numRows - 1){
                count++;
            }
            else{
                if(flag == 0){
                    count++;
                    flag = 1;
                }
                else{
                    if(j + (numRows - i - 1) * 2 < len){
                        count += 2;
                    }
                    else{
                        count++;
                    }
                    flag = 0;
                }
            }
        }
        if(count > max){
            max = count;
        }
        count = 0;
        flag = 0;
    }
    result = (char*)malloc(sizeof(char) * (max + 1));
    for(i = 0; i < numRows; i++){
        for(j = i; j < len; j += (2 * numRows - 2)){
            result[k++] = s[j];
            if(i == 0 || i == numRows - 1){
                continue;
            }
            else{
                if(flag == 0){
                    flag = 1;
                }
                else{
                    if(j + (numRows - i - 1) * 2 < len){
                        result[k++] = s[j + (numRows - i - 1) * 2];
                    }
                    flag = 0;
                }
            }
        }
        flag = 0;
    }
    result[k] = '\0';
    return result;

}

    