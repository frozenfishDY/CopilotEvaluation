/**https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/ */
//There is a donuts shop that bakes donuts in batches of batchSize. They have a rule where they must serve all of the donuts of a batch before serving any donuts of the next batch. You are given an integer batchSize and an integer array groups, where groups[i] denotes that there is a group of groups[i] customers that will visit the shop. Each customer will get exactly one donut.
//When a group visits the shop, all customers of the group must be served before serving any of the following groups. A group will be happy if they all get fresh donuts. That is, the first customer of the group does not receive a donut that was left over from the previous group.
//You can freely rearrange the ordering of the groups. Return the maximum possible number of happy groups after rearranging the groups.


int maxHappyGroups(int batchSize, int* groups, int groupsSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*groupsSize);
    for(i=0;i<groupsSize;i++){
        arr13[i] = 0;
    }

}

    