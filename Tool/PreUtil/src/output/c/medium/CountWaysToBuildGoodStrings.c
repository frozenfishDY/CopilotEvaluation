/**https://leetcode.com/problems/count-ways-to-build-good-strings/ */
//Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
//Append the character '0' zero times.
//Append the character '1' one times.
//This can be performed any number of times.
//A good string is a string constructed by the above process having a length between low and high (inclusive).
//Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.


int countGoodStrings(int low, int high, int zero, int one){
    int count = 0;
    int* arr = (int*)malloc(sizeof(int) * high);
    for(int i = 0; i < high; i++){
        arr[i] = 0;
    }
    countGoodStringsHelper(low, high, zero, one, arr, &count);
    return count;


}

    