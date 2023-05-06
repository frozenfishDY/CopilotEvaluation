#https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
#Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. You have to filter the restaurants using three filters.
#The veganFriendly filter will be either true (meaning you should only include restaurants with veganFriendlyi set to true) or false (meaning you can include any restaurant). In addition, you have the filters maxPrice and maxDistance which are the maximum value for price and distance of restaurants you should consider respectively.
#Return the array of restaurant IDs after filtering, ordered by rating from highest to lowest. For restaurants with the same rating, order them by id from highest to lowest. For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.


class Solution(object):
    def filterRestaurants(self, restaurants, veganFriendly, maxPrice, maxDistance):
        """
        :type restaurants: List[List[int]]
        :type veganFriendly: int
        :type maxPrice: int
        :type maxDistance: int
        :rtype: List[int]
        """
        res = []
        for i in range(len(restaurants)):
            if veganFriendly == 1 and restaurants[i][2] == 0:
                continue
            if restaurants[i][3] > maxPrice or restaurants[i][4] > maxDistance:
                continue
            res.append(restaurants[i])
        res.sort(key=lambda x:(x[1],x[0]),reverse=True)
        return [x[0] for x in res]
        

    