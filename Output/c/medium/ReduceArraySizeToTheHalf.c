/**https://leetcode.com/problems/reduce-array-size-to-the-half/ */
//You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
//Return the minimum size of the set so that at least half of the integers of the array are removed.


int minSetSize(int* arr, int arrSize){
    int* count = (int*)malloc(sizeof(int) * 100001);
    for(int i = 0; i < 100001; i++){
        count[i] = 0;
    }
    for(int i = 0; i < arrSize; i++){
        count[arr[i]]++;
    }
    int* count2 = (int*)malloc(sizeof(int) * 100001);
    for(int i = 0; i < 100001; i++){
        count2[i] = 0;
    }
    for(int i = 0; i < 100001; i++){
        count2[count[i]]++;
    }
    int sum = 0;
    int result = 0;
    for(int i = 100000; i >= 0; i--){
        if(count2[i] > 0){
            for(int j = 0; j < count2[i]; j++){
                sum += i;
                result++;
                if(sum >= arrSize / 2){
                    return result;
                }
            }
        }
    }
    return result;

}

    