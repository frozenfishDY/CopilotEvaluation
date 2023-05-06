#https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
#Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
#Return the restaurant's ��display table��. The ��display table�� is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is ��Table��, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.


class Solution(object):
    def displayTable(self, orders):
        """
        :type orders: List[List[str]]
        :rtype: List[List[str]]
        """   
        # 1. Get the food items and table numbers
        # 2. Create a dictionary with the table numbers as the keys and the food items as the values
        # 3. Loop through the dictionary and create a list of lists
        # 4. Return the list of lists
        food_items = set()
        table_numbers = set()
        for order in orders:
            food_items.add(order[2])
            table_numbers.add(order[1])
        table_dict = {}
        for table_number in table_numbers:
            table_dict[table_number] = {}
            for food_item in food_items:
                table_dict[table_number][food_item] = 0
        for order in orders:
            table_dict[order[1]][order[2]] += 1
        result = []
        result.append(["Table"] + sorted(list(food_items)))
        for table_number in sorted(table_dict.keys()):
            row = [table_number]
            for food_item in sorted(table_dict[table_number].keys()):
                row.append(str(table_dict[table_number][food_item]))
            result.append(row)
        return result

        

    