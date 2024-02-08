/**https://leetcode.com/problems/maximum-number-of-visible-points/ */
//You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.
//Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].


int visiblePoints(int** points, int pointsSize, int* pointsColSize, int angle, int* location, int locationSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*pointsSize);
    for(i=0;i<pointsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<pointsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<pointsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;


}

    