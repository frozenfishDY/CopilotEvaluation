/**https://leetcode.com/problems/largest-time-for-given-digits/ */
//Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
//24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
//Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.


class LargestTimeForGivenDigits {
    public String largestTimeFromDigits(int[] arr) {
        int max = -1;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(j == i){
                    continue;
                }
                for(int k = 0; k < 4; k++){
                    if(k == i || k == j){
                        continue;
                    }
                    int l = 6 - i - j - k;
                    int h = arr[i] * 10 + arr[j];
                    int m = arr[k] * 10 + arr[l];
                    if(h < 24 && m < 60){
                        max = Math.max(max, h * 60 + m);
                    }
                }
            }
        }
        if(max == -1){
            return "";
        }
        return String.format("%02d:%02d", max / 60, max % 60);
        
        
    }
}

    