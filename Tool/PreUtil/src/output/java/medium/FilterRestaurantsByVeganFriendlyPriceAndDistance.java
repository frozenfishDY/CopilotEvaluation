/**https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/ */
//Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. You have to filter the restaurants using three filters.
//The veganFriendly filter will be either true (meaning you should only include restaurants with veganFriendlyi set to true) or false (meaning you can include any restaurant). In addition, you have the filters maxPrice and maxDistance which are the maximum value for price and distance of restaurants you should consider respectively.
//Return the array of restaurant IDs after filtering, ordered by rating from highest to lowest. For restaurants with the same rating, order them by id from highest to lowest. For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.


class FilterRestaurantsByVeganFriendlyPriceAndDistance {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        List<int[]> list = new ArrayList<>();
        for(int[] r : restaurants){
            if(veganFriendly == 1 && r[2] == 0){
                continue;
            }
            if(r[3] > maxPrice || r[4] > maxDistance){
                continue;
            }
            list.add(r);
        }
        Collections.sort(list, (a, b) -> {
            if(a[1] == b[1]){
                return b[0] - a[0];
            }
            return b[1] - a[1];
        });
        List<Integer> res = new ArrayList<>();
        for(int[] r : list){
            res.add(r[0]);
        }
        return res;
        
        
    }
}

    