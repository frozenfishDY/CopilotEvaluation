/**https://leetcode.com/problems/candy/ */
//There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
//You are giving candies to these children subjected to the following requirements:
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute the candies to the children.


int candy(int* ratings, int ratingsSize){
    int* candies = (int*)malloc(sizeof(int) * ratingsSize);
    memset(candies, 0, sizeof(int) * ratingsSize);
    candies[0] = 1;
    for(int i = 1; i < ratingsSize; i++){
        if(ratings[i] > ratings[i - 1]){
            candies[i] = candies[i - 1] + 1;
        }else{
            candies[i] = 1;
        }
    }
    for(int i = ratingsSize - 2; i >= 0; i--){
        if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]){
            candies[i] = candies[i + 1] + 1;
        }
    }
    int sum = 0;
    for(int i = 0; i < ratingsSize; i++){
        sum += candies[i];
    }
    return sum;
    
}

    