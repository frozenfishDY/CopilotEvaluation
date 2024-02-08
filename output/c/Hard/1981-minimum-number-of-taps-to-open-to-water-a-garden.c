/**https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/ */
//There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).
//There are n + 1 taps located at points [0, 1, ..., n] in the garden.
//Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.
//Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.


int minTaps(int n, int* ranges, int rangesSize){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    for(i=0;i<rangesSize;i++){
        if(ranges[i]>0){
            int start = i-ranges[i];
            int end = i+ranges[i];
            if(start<0){
                start = 0;
            }
            if(end>n){
                end = n;
            }
            for(j=start;j<end;j++){
                arr[j] = 1;
            }
        }
    }
    int ans = 0;
    int flag = 0;
    while(flag==0){
        flag = 1;
        for(i=0;i<n;i++){
            if(arr[i]==0){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            break;
        }
        for(i=0;i<n;i++){
            if(arr[i]==0){
                arr[i] = 1;
                break;
            }
        }
        ans++;
    }
    return ans;

}

    