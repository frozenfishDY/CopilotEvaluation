/**https://leetcode.com/problems/reduce-array-size-to-the-half/ */
//You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
//Return the minimum size of the set so that at least half of the integers of the array are removed.


class ReduceArraySizeToTheHalf {
    public int minSetSize(int[] arr) {
        int n = arr.length;
        int[] count = new int[100001];
        for(int i : arr){
            count[i]++;
        }
        Arrays.sort(count);
        int res = 0;
        int sum = 0;
        for(int i = count.length - 1; i >= 0; i--){
            if(sum >= n / 2){
                break;
            }
            sum += count[i];
            res++;
        }
        return res;
        
        
    }
}

    