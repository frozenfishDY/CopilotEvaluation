/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.


char * minInteger(char * num, int k){
    int i,j;
    int len = strlen(num);
    int* arr = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr[i] = num[i]-'0';
    }
    int* arr2 = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr2[i] = 0;
    }
    for(i=0;i<len;i++){
        int min = 10;
        int index = 0;
        for(j=i;j<len;j++){
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        if(index-i>k){
            for(j=i;j<len;j++){
                if(arr[j]==min){
                    index = j;
                    break;
                }
            }
        }
        arr2[i] = arr[index];
        for(j=index;j>i;j--){
            arr[j] = arr[j-1];
        }
        k = k-(index-i);
    }
    char* str = (char*)malloc(sizeof(char)*len);
    for(i=0;i<len;i++){
        str[i] = arr2[i]+'0';
    }
    return str;

}

    