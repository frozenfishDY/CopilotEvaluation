/**https://leetcode.com/problems/keys-and-rooms/ */
//There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
//When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
//Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.


bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int* visited = (int*)malloc(sizeof(int) * roomsSize);
    for(int i = 0; i < roomsSize; i++){
        visited[i] = 0;
    }
    visited[0] = 1;
    int count = 1;
    int* stack = (int*)malloc(sizeof(int) * roomsSize);
    int top = 0;
    stack[top++] = 0;
    while(top != 0){
        int room = stack[--top];
        for(int i = 0; i < roomsColSize[room]; i++){
            if(visited[rooms[room][i]] == 0){
                visited[rooms[room][i]] = 1;
                count++;
                stack[top++] = rooms[room][i];
            }
        }
    }
    return count == roomsSize;

}

    