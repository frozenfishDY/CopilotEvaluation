/**https://leetcode.com/problems/remove-k-digits/ */
//Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


char * removeKdigits(char * num, int k){
    int len = strlen(num);
    if(len == k){
        return "0";
    }
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int top = 0;
    for(int i = 0; i < len; i++){
        while(top > 0 && result[top - 1] > num[i] && k > 0){
            top--;
            k--;
        }
        result[top++] = num[i];
    }
    top -= k;
    result[top] = '\0';
    int index = 0;
    while(result[index] == '0'){
        index++;
    }
    if(index == top){
        return "0";
    }
    return result + index;

}

    