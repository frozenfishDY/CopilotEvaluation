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
int countDaysTogether(char * arriveAlice, char * leaveAlice, char * arriveBob, char * leaveBob){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int a4 = 0;
    int b1 = 0;
    int b2 = 0;
    int b3 = 0;
    int b4 = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    a1 = (arriveAlice[0] - '0') * 10 + arriveAlice[1] - '0';
    a2 = (arriveAlice[3] - '0') * 10 + arriveAlice[4] - '0';
    a3 = (leaveAlice[0] - '0') * 10 + leaveAlice[1] - '0';
    a4 = (leaveAlice[3] - '0') * 10 + leaveAlice[4] - '0';
    b1 = (arriveBob[0] - '0') * 10 + arriveBob[1] - '0';
    b2 = (arriveBob[3] - '0') * 10 + arriveBob[4] - '0';
    b3 = (leaveBob[0] - '0') * 10 + leaveBob[1] - '0';
    b4 = (leaveBob[3] - '0') * 10 + leaveBob[4] - '0';
    a = a1 * 100 + a2;
    b = a3 * 100 + a4;
    c = b1 * 100 + b2;
    d = b3 * 100 + b4;
    if (a > b || c > d) {
        return 0;
    }
    if (b < c || d < a) {
        return 0;
    }
    return (b > d ? d : b) - (a > c ? a : c) + 1;
}