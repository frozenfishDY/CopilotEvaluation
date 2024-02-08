/**https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/ */
//You are given a list of songs where the ith song has a duration of time[i] seconds.
//Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.


/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    let result = 0;
    let n = time.length;
    let map = new Map();
    for(let i = 0; i < n; i++){
        let mod = time[i] % 60;
        let diff = (60 - mod) % 60;
        if(map.has(diff)){
            result += map.get(diff);
        }
        if(map.has(mod)){
            map.set(mod, map.get(mod) + 1);
        }else{
            map.set(mod, 1);
        }
    }
    return result;
    
};

    