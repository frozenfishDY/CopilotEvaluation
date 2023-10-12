/**https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/ */
//You are given an integer num. You will apply the following steps exactly two times:
//	Pick a digit x (0 <= x <= 9).
//	Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
//	Replace all the occurrences of x in the decimal representation of num by y.
//	The new integer cannot have any leading zeros, also the new integer cannot be 0.
//Let a and b be the results of applying the operations to num the first and second times, respectively.
//Return the max difference between a and b.
// 
//Example 1:
//Input: num = 555
//Output: 888
//Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
//The second time pick x = 5 and y = 1 and store the new integer in b.
//We have now a = 999 and b = 111 and max difference = 888
//Example 2:
//Input: num = 9
//Output: 8
//Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
//The second time pick x = 9 and y = 1 and store the new integer in b.
//We have now a = 9 and b = 1 and max difference = 8
// 
//Constraints:
//	1 <= num <= 108
int maxDiff(int num){
int i, j, k, max, min;
	char *s_num = (char *)malloc(sizeof(char) * 10);
	memset(s_num, 0, sizeof(char) * 10);
	sprintf(s_num, "%d", num);
	max = num;
	min = num;
	for(i = 0; i < strlen(s_num); i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(s_num[i] - '0' == j)
			{
				continue;
			}
			for(k = 0; k < strlen(s_num); k++)
			{
				if(s_num[k] - '0' == j)
				{
					s_num[k] = s_num[i];
				}
			}
			if(s_num[0] == '0')
			{
				continue;
			}
			if(atoi(s_num) > max)
			{
				max = atoi(s_num);
			}
			if(atoi(s_num) < min)
			{
				min = atoi(s_num);
			}
			sprintf(s_num, "%d", num);
		}
	}
	return max - min;
}