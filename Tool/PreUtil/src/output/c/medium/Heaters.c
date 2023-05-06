/**https://leetcode.com/problems/heaters/ */
//Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
//Every house can be warmed, as long as the house is within the heater's warm radius range. 
//Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
//Notice that all the heaters follow your radius standard, and the warm radius will the same.


int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    int result = 0;
    for(int i = 0; i < housesSize; i++){
        int min = INT_MAX;
        for(int j = 0; j < heatersSize; j++){
            int temp = abs(houses[i] - heaters[j]);
            if(temp < min){
                min = temp;
            }
        }
        if(min > result){
            result = min;
        }
    }
    return result;

}

    