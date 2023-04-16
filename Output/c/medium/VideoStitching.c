/**https://leetcode.com/problems/video-stitching/ */
//You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.
//Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.
//We can cut these clips into segments freely.
//For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
//Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.


int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time){
    int* hash = (int*)malloc(sizeof(int) * (time + 1));
    for(int i = 0; i < time + 1; i++){
        hash[i] = -1;
    }
    hash[0] = 0;
    for(int i = 0; i < clipsSize; i++){
        if(clips[i][0] < time + 1 && hash[clips[i][0]] != -1){
            for(int j = clips[i][0] + 1; j < time + 1 && j <= clips[i][1]; j++){
                if(hash[j] == -1 || hash[j] > hash[clips[i][0]] + 1){
                    hash[j] = hash[clips[i][0]] + 1;
                }
            }
        }
    }
    return hash[time];

}

    