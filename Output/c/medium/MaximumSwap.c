/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.


int maximumSwap(int num){
    int* digits = (int*)malloc(sizeof(int) * 10);
    int digitCount = 0;
    while(num > 0){
        digits[digitCount++] = num % 10;
        num /= 10;
    }
    for(int i = 0; i < digitCount; i++){
        int max = digits[i];
        int maxIndex = i;
        for(int j = i + 1; j < digitCount; j++){
            if(digits[j] >= max){
                max = digits[j];
                maxIndex = j;
            }
        }
        if(maxIndex != i){
            int temp = digits[i];
            digits[i] = digits[maxIndex];
            digits[maxIndex] = temp;
            break;
        }
    }
    int result = 0;
    for(int i = digitCount - 1; i >= 0; i--){
        result = result * 10 + digits[i];
    }
    return result;

}

    