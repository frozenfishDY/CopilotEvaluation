/**https://leetcode.com/problems/maximum-number-of-visible-points/ */
//You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.
//Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].


/**
 * @param {number[][]} points
 * @param {number} angle
 * @param {number[]} location
 * @return {number}
 */
var visiblePoints = function(points, angle, location) {
    let x = location[0];
    let y = location[1];
    let n = points.length;
    let arr = [];
    let cnt = 0;
    for(let i = 0; i < n; i++){
        let [a, b] = points[i];
        if(a == x && b == y){
            cnt++;
        }else{
            arr.push(Math.atan2(b - y, a - x));
        }
    }
    arr.sort((a, b) => a - b);
    let m = arr.length;
    let ans = 0;
    for(let i = 0; i < m; i++){
        arr.push(arr[i] + 2 * Math.PI);
    }
    let l = 0;
    for(let r = 0; r < 2 * m; r++){
        while(arr[r] - arr[l] > angle * Math.PI / 180){
            l++;
        }
        ans = Math.max(ans, r - l + 1);
    }
    return ans + cnt;
    
};

    