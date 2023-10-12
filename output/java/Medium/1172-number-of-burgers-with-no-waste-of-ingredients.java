/**https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/ */
//Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:
//	Jumbo Burger: 4 tomato slices and 1 cheese slice.
//	Small Burger: 2 Tomato slices and 1 cheese slice.
//Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].
// 
//Example 1:
//Input: tomatoSlices = 16, cheeseSlices = 7
//Output: [1,6]
//Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
//There will be no remaining ingredients.
//Example 2:
//Input: tomatoSlices = 17, cheeseSlices = 4
//Output: []
//Explantion: There will be no way to use all ingredients to make small and jumbo burgers.
//Example 3:
//Input: tomatoSlices = 4, cheeseSlices = 17
//Output: []
//Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
// 
//Constraints:
//	0 <= tomatoSlices, cheeseSlices <= 107
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // 1. create a list to store the result
		// 2. check if the number of tomato slices is even
		// 2.1 if not, return the empty list
		// 3. check if the number of tomato slices is greater than or equal to twice the number of cheese slices
		// 3.1 if not, return the empty list
		// 4. check if the number of cheese slices is greater than or equal to half the number of tomato slices
		// 4.1 if not, return the empty list
		// 5. add the number of jumbo burgers and the number of small burgers to the list
		// 6. return the list
        List<Integer> list = new ArrayList<>();
        if(tomatoSlices % 2 != 0) {
            return list;
        }
        if(tomatoSlices < 2*cheeseSlices) {
            return list;
        }
        if(cheeseSlices < tomatoSlices/2) {
            return list;
        }
        list.add(tomatoSlices/2-cheeseSlices);
        list.add(2*cheeseSlices-tomatoSlices/2);
        return list;
    }
}