/**https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/ */
//There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
//Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
//Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold){
    int** graph = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        graph[i] = (int*)malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            graph[i][j] = 10001;
        }
        graph[i][i] = 0;
    }
    for(int i = 0; i < edgesSize; i++){
        graph[edges[i][0]][edges[i][1]] = edges[i][2];
        graph[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    int result = 0;
    int min = n;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(graph[i][j] <= distanceThreshold){
                count++;
            }
        }
        if(count <= min){
            min = count;
            result = i;
        }
    }
    return result;

}

    