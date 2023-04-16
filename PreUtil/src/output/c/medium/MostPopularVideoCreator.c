/**https://leetcode.com/problems/most-popular-video-creator/ */
//You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.
//The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
//If multiple creators have the highest popularity, find all of them.
//If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
//Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** mostPopularCreator(char ** creators, int creatorsSize, char ** ids, int idsSize, int* views, int viewsSize, int* returnSize, int** returnColumnSizes){
    char*** arr = malloc(creatorsSize * sizeof(char**));
    int i, j, k, l;
    int count = 0;
    for(i = 0; i < creatorsSize; i++){
        arr[i] = malloc(2 * sizeof(char*));
        for(j = 0; j < 2; j++){
            arr[i][j] = malloc(100 * sizeof(char));
        }
    }
    for(i = 0; i < creatorsSize; i++){
        for(j = i + 1; j < creatorsSize; j++){
            if(strcmp(creators[i], creators[j]) == 0){
                views[i] += views[j];
                views[j] = 0;
            }
        }
    }
    for(i = 0; i < creatorsSize; i++){
        for(j = i + 1; j < creatorsSize; j++){
            if(views[i] < views[j]){
                int temp = views[i];
                views[i] = views[j];
                views[j] = temp;
                char* temp1 = creators[i];
                creators[i] = creators[j];
                creators[j] = temp1;
                char* temp2 = ids[i];
                ids[i] = ids[j];
                ids[j] = temp2;
            }
        }
    }
    for(i = 0; i < creatorsSize; i++){
        if(views[i] == 0){
            break;
        }
        for(j = i + 1; j < creatorsSize; j++){
            if(views[i] == views[j]){
                for(k = 0; k < 100; k++){
                    if(ids[i][k] < ids[j][k]){
                        break;
                    }
                    else if(ids[i][k] > ids[j][k]){
                        char* temp = ids[i];
                        ids[i] = ids[j];
                        ids[j] = temp;
                        break;
                    }
                }
            }
        }
    }
    for(i = 0; i < creatorsSize; i++){
        if(views[i] == 0){
            break;
        }
        for(j = i + 1; j < creatorsSize; j++){
            if(views[i] == views[j]){
                for(k = 0; k < 100; k++){
                    if(creators[i][k] < creators[j][k]){
                        break ;

        
        

}

    