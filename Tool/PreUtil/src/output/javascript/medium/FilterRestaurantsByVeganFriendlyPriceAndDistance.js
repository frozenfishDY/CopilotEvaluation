/**https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/ */
//Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. You have to filter the restaurants using three filters.
//The veganFriendly filter will be either true (meaning you should only include restaurants with veganFriendlyi set to true) or false (meaning you can include any restaurant). In addition, you have the filters maxPrice and maxDistance which are the maximum value for price and distance of restaurants you should consider respectively.
//Return the array of restaurant IDs after filtering, ordered by rating from highest to lowest. For restaurants with the same rating, order them by id from highest to lowest. For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.


/**
 * @param {number[][]} restaurants
 * @param {number} veganFriendly
 * @param {number} maxPrice
 * @param {number} maxDistance
 * @return {number[]}
 */
var filterRestaurants = function(restaurants, veganFriendly, maxPrice, maxDistance) {
    let result = [];
    for(let i = 0; i < restaurants.length; i++){
        if(veganFriendly == 1 && restaurants[i][2] == 0){
            continue;
        }
        if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
            result.push(restaurants[i]);
        }
    }
    result.sort((a, b) => {
        if(a[1] == b[1]){
            return b[0] - a[0];
        }
        return b[1] - a[1];
    });
    let finalResult = [];
    for(let i = 0; i < result.length; i++){
        finalResult.push(result[i][0]);
    }
    return finalResult;
    
};

    