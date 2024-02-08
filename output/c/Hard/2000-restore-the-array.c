/**https://leetcode.com/problems/restore-the-array/ */
//A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.
//Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 10^9 + 7.


int numberOfArrays(char * s, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*100000);
    for(i=0;i<100000;i++){
        arr[i] = 0;
    }
    int len = strlen(s);
    int* arr2 = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr2[i] = 0;
    }
    for(i=0;i<len;i++){
        if(s[i]=='0'){
            return 0;
        }
        int num = 0;
        for(j=i;j<len;j++){
            num = num*10 + (s[j]-'0');
            if(num<=k){
                if(i==0){
                    arr[j] = 1;
                }
                else{
                    arr[j] = (arr[j] + arr2[i-1]) % 1000000007;
                }
            }
            else{
                break;
            }
        }
        for(j=0;j<len;j++){
            arr2[j] = arr[j];
        }
    }
    return arr[len-1];

}

    