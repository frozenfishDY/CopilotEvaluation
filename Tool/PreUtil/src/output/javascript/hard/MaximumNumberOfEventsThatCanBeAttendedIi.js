/**https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/ */
//You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
//You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
//Return the maximum sum of values that you can receive by attending events.


/**
 * @param {number[][]} events
 * @param {number} k
 * @return {number}
 */
var maxValue = function(events, k) {
    let n = events.length;
    events.sort((a, b) => a[1] - b[1]);
    let dp = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        dp[i] = events[i - 1][2];
    }
    for(let i = 1; i < k; i++){
        let dp2 = new Array(n + 1).fill(0);
        for(let j = 1; j <= n; j++){
            let left = 0;
            let right = j;
            while(left < right){
                let mid = Math.floor((left + right) / 2);
                if(events[mid - 1][1] < events[j - 1][0]){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            dp2[j] = Math.max(dp2[j - 1], dp[left - 1] + events[j - 1][2]);
        }
        dp = dp2;
    }
    return dp[n];
    
    
};

    