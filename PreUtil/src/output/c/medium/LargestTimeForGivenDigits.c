/**https://leetcode.com/problems/largest-time-for-given-digits/ */
//Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
//24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
//Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.


char * largestTimeFromDigits(int* arr, int arrSize){
    int max = -1;
    int hour = 0;
    int minute = 0;
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < arrSize; j++){
            if(j == i){
                continue;
            }
            for(int k = 0; k < arrSize; k++){
                if(k == i || k == j){
                    continue;
                }
                int l = 6 - i - j - k;
                int h = arr[i] * 10 + arr[j];
                int m = arr[k] * 10 + arr[l];
                if(h < 24 && m < 60 && h * 60 + m > max){
                    max = h * 60 + m;
                    hour = h;
                    minute = m;
                }
            }
        }
    }
    if(max == -1){
        return "";
    }
    char* result = (char*)malloc(sizeof(char) * 6);
    sprintf(result, "%02d:%02d", hour, minute);
    return result;

}

    