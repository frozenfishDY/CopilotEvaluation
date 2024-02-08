/**https://leetcode.com/problems/bus-routes/ */
//You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
//For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
//You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
//Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.


int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int source, int target){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    if(source == target){
        return 0;
    }
    int* visited = (int*)malloc(sizeof(int) * routesSize);
    for(i = 0; i < routesSize; i++){
        visited[i] = 0;
    }
    int* queue = (int*)malloc(sizeof(int) * routesSize);
    int front = 0;
    int rear = 0;
    for(i = 0; i < routesSize; i++){
        for(j = 0; j < routesColSize[i]; j++){
            if(routes[i][j] == source){
                queue[rear++] = i;
                visited[i] = 1;
                break;
            }
        }
    }
    int step = 1;
    while(front < rear){
        int size = rear - front;
        for(i = 0; i < size; i++){
            int bus = queue[front++];
            for(j = 0; j < routesColSize[bus]; j++){
                if(routes[bus][j] == target){
                    return step;
                }
                for(k = 0; k < routesSize; k++){
                    if(visited[k] == 0){
                        for(l = 0; l < routesColSize[k]; l++){
                            if(routes[k][l] == routes[bus][j]){
                                queue[rear++] = k;
                                visited[k] = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        step++;
    }
    return -1;

}

    