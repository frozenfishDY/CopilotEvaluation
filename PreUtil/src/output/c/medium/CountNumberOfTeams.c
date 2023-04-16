/**https://leetcode.com/problems/count-number-of-teams/ */
//There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
//You have to form a team of 3 soldiers amongst them under the following rules:
//Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
//A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
//Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).


int numTeams(int* rating, int ratingSize){
    int i, j, k, count = 0;
    for(i = 0; i < ratingSize - 2; i++){
        for(j = i + 1; j < ratingSize - 1; j++){
            for(k = j + 1; k < ratingSize; k++){
                if((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])){
                    count++;
                }
            }
        }
    }
    return count;

}

    