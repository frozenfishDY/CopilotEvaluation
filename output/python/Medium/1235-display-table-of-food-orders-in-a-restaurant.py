#https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
#Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders._x000D_
#_x000D_
#Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]_x000D_
#Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] _x000D_
#Explanation:_x000D_
#The displaying table looks like:_x000D_
#Table,Beef Burrito,Ceviche,Fried Chicken,Water_x000D_
#3    ,0           ,2      ,1            ,0_x000D_
#5    ,0           ,1      ,0            ,1_x000D_
#10   ,1           ,0      ,0            ,0_x000D_
#For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche"._x000D_
#For the table 5: Carla orders "Water" and "Ceviche"._x000D_
#For the table 10: Corina orders "Beef Burrito". _x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]_x000D_
#Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] _x000D_
#Explanation: _x000D_
#For the table 1: Adam and Brianna order "Canadian Waffles"._x000D_
#For the table 12: James, Ratesh and Amadeus order "Fried Chicken"._x000D_
#_x000D_
#_x000D_
#Example 3:_x000D_
#_x000D_
#_x000D_
#Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]_x000D_
#Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= orders.length <= 5 * 10^4_x000D_
#	orders[i].length == 3_x000D_
#	1 <= customerNamei.length, foodItemi.length <= 20_x000D_
#	customerNamei and foodItemi consist of lowercase and uppercase English letters and the space character._x000D_
#	tableNumberi is a valid integer between 1 and 500._x000D_
class Solution(object):_x000D_
    def displayTable(self, orders):_x000D_
        """_x000D_
        :type orders: List[List[str]]_x000D_
        :rtype: List[List[str]]_x000D_
        """