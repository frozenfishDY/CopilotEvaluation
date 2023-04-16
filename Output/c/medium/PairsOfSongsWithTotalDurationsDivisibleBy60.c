/**https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/ */
//You are given a list of songs where the ith song has a duration of time[i] seconds.
//Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.


int numPairsDivisibleBy60(int* time, int timeSize){
    int* hash = (int*)malloc(sizeof(int) * 60);
    for(int i = 0; i < 60; i++){
        hash[i] = 0;
    }
    int result = 0;
    for(int i = 0; i < timeSize; i++){
        int remainder = time[i] % 60;
        if(remainder == 0){
            result += hash[0];
        }else{
            result += hash[60 - remainder];
        }
        hash[remainder]++;
    }
    return result;

}

    