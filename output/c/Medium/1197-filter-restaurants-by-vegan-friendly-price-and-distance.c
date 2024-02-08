/**https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/ */
//Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. You have to filter the restaurants using three filters.
//The veganFriendly filter will be either true (meaning you should only include restaurants with veganFriendlyi set to true) or false (meaning you can include any restaurant). In addition, you have the filters maxPrice and maxDistance which are the maximum value for price and distance of restaurants you should consider respectively.
//Return the array of restaurant IDs after filtering, ordered by rating from highest to lowest. For restaurants with the same rating, order them by id from highest to lowest. For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize){
    int* result = malloc(sizeof(int) * restaurantsSize);
    int resultSize = 0;
    for(int i = 0; i < restaurantsSize; i++){
        if(veganFriendly == 1 && restaurants[i][2] == 0){
            continue;
        }
        if(restaurants[i][3] > maxPrice){
            continue;
        }
        if(restaurants[i][4] > maxDistance){
            continue;
        }
        result[resultSize++] = restaurants[i][0];
    }
    for(int i = 0; i < resultSize; i++){
        for(int j = i + 1; j < resultSize; j++){
            if(restaurants[result[i] - 1][1] < restaurants[result[j] - 1][1]){
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
            else if(restaurants[result[i] - 1][1] == restaurants[result[j] - 1][1]){
                if(result[i] < result[j]){
                    int temp = result[i];
                    result[i] = result[j];
                    result[j] = temp;
                }
            }
        }
    }
    *returnSize = resultSize;
    return result;

}

    