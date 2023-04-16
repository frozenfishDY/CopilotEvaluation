/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.


char * convertToBase7(int num){
    char* ans = (char*)malloc(12 * sizeof(char));
    int i = 0;
    if(num == 0){
        ans[i] = '0';
        i++;
    }else{
        int sign = 1;
        if(num < 0){
            sign = -1;
            num = -num;
        }
        while(num > 0){
            ans[i] = num % 7 + '0';
            num /= 7;
            i++;
        }
        if(sign == -1){
            ans[i] = '-';
            i++;
        }
    }
    ans[i] = '\0';
    int j = 0;
    i--;
    while(j < i){
        char temp = ans[j];
        ans[j] = ans[i];
        ans[i] = temp;
        j++;
        i--;
    }
    return ans;
    

}

    