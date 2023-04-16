/**https://leetcode.com/problems/magical-string/ */
//A magical string s consists of only '1' and '2' and obeys the following rules:
//The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string s itself.
//The first few elements of s is s = "1221121221221121122����". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.
//Given an integer n, return the number of 1's in the first n number in the magical string s.


int magicalString(int n){
    if(n == 0){
        return 0;
    }
    if(n <= 3){
        return 1;
    }
    int* result = (int*)malloc(sizeof(int) * n);
    result[0] = 1;
    result[1] = 2;
    result[2] = 2;
    int count = 1;
    int index = 2;
    int i = 3;
    while(i < n){
        for(int j = 0; j < result[index]; j++){
            result[i++] = 3 - result[i - 1];
            if(result[i - 1] == 1 && i <= n){
                count++;
            }
        }
        index++;
    }
    return count;

}

    