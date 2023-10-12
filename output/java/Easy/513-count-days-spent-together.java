/**https://leetcode.com/problems/count-days-spent-together/ */
//Alice and Bob are traveling to Rome for separate business meetings.
//You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
//Return the total number of days that Alice and Bob are in Rome together.
//You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
// 
//Example 1:
//Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
//Output: 3
//Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
//Example 2:
//Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
//Output: 0
//Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.
// 
//Constraints:
//	All dates are provided in the format "MM-DD".
//	Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
//	The given dates are valid dates of a non-leap year.
class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] days = new int[]{31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31};
        int[] first = new int[2];
        int[] second = new int[2];
        first[0] = Integer.parseInt(arriveAlice.substring(0, 2));
        first[1] = Integer.parseInt(arriveAlice.substring(3, 5));
        second[0] = Integer.parseInt(arriveBob.substring(0, 2));
        second[1] = Integer.parseInt(arriveBob.substring(3, 5));
        int res = 0;
        while (true) {
            if (first[0] == second[0] && first[1] == second[1]) {
                res++;
            }
            if (first[0] == Integer.parseInt(leaveAlice.substring(0, 2)) && first[1] == Integer.parseInt(leaveAlice.substring(3, 5))) {
                break;
            }
            if (second[0] == Integer.parseInt(leaveBob.substring(0, 2)) && second[1] == Integer.parseInt(leaveBob.substring(3, 5))) {
                break;
            }
            first[1]++;
            if (first[1] > days[first[0] - 1]) {
                first[1] = 1;
                first[0]++;
            }
            if (first[0] > 12) {
                first[0] = 1;
            }
            second[1]++;
            if (second[1] > days[second[0] - 1]) {
                second[1] = 1;
                second[0]++;
            }
            if (second[0] > 12) {
                second[0] = 1;
            }
        }
        return res;
    }
}