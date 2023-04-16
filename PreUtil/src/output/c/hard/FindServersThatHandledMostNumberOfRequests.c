/**https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/ */
//You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:
//The ith (0-indexed) request arrives.
//If all servers are busy, the request is dropped (not handled at all).
//If the (i % k)th server is available, assign the request to that server.
//Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
//You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.
//Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr14[i] = 0;
    }
    int* arr15 =

}

    