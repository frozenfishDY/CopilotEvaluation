/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 10^9 + 7.


int waysToBuildRooms(int* prevRoom, int prevRoomSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*prevRoomSize);
    for(i=0;i<prevRoomSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<prevRoomSize;i++){
        int num = 0;
        for(j=prevRoom[i];j<i;j++){
            num = num*10 + (prevRoom[j]-'0');
            if(num<=100000){
                if(i==0){
                    arr[j] = 1;
                }
                else{
                    arr[j] = (arr[j] + arr2[i-1]) % 1000000007;
                }
            }
            else{
                break;
            }
        }
        for(j=0;j<prevRoomSize;j++){
            arr2[j] = arr[j];
        }
    }
    return arr[prevRoomSize-1];

}

    