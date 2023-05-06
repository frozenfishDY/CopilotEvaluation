/**https://leetcode.com/problems/video-stitching/ */
//You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.
//Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.
//We can cut these clips into segments freely.
//For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
//Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.


/**
 * @param {number[][]} clips
 * @param {number} time
 * @return {number}
 */
var videoStitching = function(clips, time) {
    let n = clips.length;
    let dp = new Array(time + 1).fill(Infinity);
    dp[0] = 0;
    for(let i = 1; i <= time; i++){
        for(let j = 0; j < n; j++){
            if(clips[j][0] < i && clips[j][1] >= i){
                dp[i] = Math.min(dp[i], dp[clips[j][0]] + 1);
            }
        }
    }
    return dp[time] == Infinity ? -1 : dp[time];
    
};

    