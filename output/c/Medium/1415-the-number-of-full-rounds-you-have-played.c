/**https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/ */
//You are participating in an online chess tournament. There is a chess round that starts every 15 minutes. The first round of the day starts at 00:00, and after every 15 minutes, a new round starts.
//	For example, the second round starts at 00:15, the fourth round starts at 00:45, and the seventh round starts at 01:30.
//You are given two strings loginTime and logoutTime where:
//	loginTime is the time you will login to the game, and
//	logoutTime is the time you will logout from the game.
//If logoutTime is earlier than loginTime, this means you have played from loginTime to midnight and from midnight to logoutTime.
//Return the number of full chess rounds you have played in the tournament.
//Note: All the given times follow the 24-hour clock. That means the first round of the day starts at 00:00 and the last round of the day starts at 23:45.
// 
//Example 1:
//Input: loginTime = "09:31", logoutTime = "10:14"
//Output: 1
//Explanation: You played one full round from 09:45 to 10:00.
//You did not play the full round from 09:30 to 09:45 because you logged in at 09:31 after it began.
//You did not play the full round from 10:00 to 10:15 because you logged out at 10:14 before it ended.
//Example 2:
//Input: loginTime = "21:30", logoutTime = "03:00"
//Output: 22
//Explanation: You played 10 full rounds from 21:30 to 00:00 and 12 full rounds from 00:00 to 03:00.
//10 + 12 = 22.
// 
//Constraints:
//	loginTime and logoutTime are in the format hh:mm.
//	00 <= hh <= 23
//	00 <= mm <= 59
//	loginTime and logoutTime are not equal.
int numberOfRounds(char * loginTime, char * logoutTime){
int login_hour=0;
    int login_min=0;
    int logout_hour=0;
    int logout_min=0;
    int i;
    for(i=0;i<strlen(loginTime);i++){
        if(i<=1){
            login_hour=login_hour*10+loginTime[i]-'0';
        }else if(i>=3){
            login_min=login_min*10+loginTime[i]-'0';
        }
    }
    for(i=0;i<strlen(logoutTime);i++){
        if(i<=1){
            logout_hour=logout_hour*10+logoutTime[i]-'0';
        }else if(i>=3){
            logout_min=logout_min*10+logoutTime[i]-'0';
        }
    }
    int login_time=login_hour*60+login_min;
    int logout_time=logout_hour*60+logout_min;
    if(logout_time<login_time){
        logout_time+=24*60;
    }
    int start_time=(login_time/15+1)*15;
    int end_time=(logout_time/15)*15;
    if(end_time<start_time){
        return 0;
    }else{
        return (end_time-start_time)/15;
    }
}