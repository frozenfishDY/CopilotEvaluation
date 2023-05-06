/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//First, change some characters of s to other lowercase English letters.
//Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.


int palindromePartition(char * s, int k){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr[i] = 0;
    }
    int count = 0;
    int temp = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr[count] = temp;
            temp = 0;
            count++;
        }
        else{
            temp = temp*10 + (s[i]-'0');
        }
    }
    arr[count] = temp;
    count++;
    int* arr2 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr2[i] = 0;
    }
    int count2 = 0;
    int temp2 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr2[count2] = temp2;
            temp2 = 0;
            count2++;
        }
        else{
            temp2 = temp2*10 + (s[i]-'0');
        }
    }
    arr2[count2] = temp2;
    count2++;
    int* arr3 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr3[i] = 0;
    }
    int count3 = 0;
    int temp3 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr3[count3] = temp3;
            temp3 = 0;
            count3++;
        }
        else{
            temp3 = temp3*10 + (s[i]-'0');
        }
    }
    arr3[count3] = temp3;
    count3++;
    int* arr4 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr4[i] = 0;
    }
    int count4 = 0;
    int temp4 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr4[count4] = temp4;
            temp4 = 0;
            count4++;
        }
        else{
            temp4 = temp4*10 + (s[i]-'0 ');

}

    