/**https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ */
//Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
//Return the restaurant's ��display table��. The ��display table�� is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is ��Table��, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.


class DisplayTableOfFoodOrdersInARestaurant {
    public List<List<String>> displayTable(List<List<String>> orders) {
        Set<String> foodItems = new HashSet<>();
        Map<Integer, Map<String, Integer>> map = new HashMap<>();
        for(List<String> order : orders){
            String name = order.get(0);
            int table = Integer.parseInt(order.get(1));
            String food = order.get(2);
            foodItems.add(food);
            if(!map.containsKey(table)){
                map.put(table, new HashMap<>());
            }
            Map<String, Integer> tableMap = map.get(table);
            tableMap.put(food, tableMap.getOrDefault(food, 0) + 1);
        }
        List<String> foodList = new ArrayList<>(foodItems);
        Collections.sort(foodList);
        List<List<String>> res = new ArrayList<>();
        List<String> header = new ArrayList<>();
        header.add("Table");
        header.addAll(foodList);
        res.add(header);
        List<Integer> tables = new ArrayList<>(map.keySet());
        Collections.sort(tables);
        for(int table : tables){
            List<String> row = new ArrayList<>();
            row.add(String.valueOf(table));
            Map<String, Integer> tableMap = map.get(table);
            for(String food : foodList){
                row.add(String.valueOf(tableMap.getOrDefault(food, 0)));
            }
            res.add(row);
        }
        return res;
        
    }
}

    