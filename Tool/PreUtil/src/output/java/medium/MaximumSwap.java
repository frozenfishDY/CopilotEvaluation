/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.


class MaximumSwap {
    public int maximumSwap(int num) {
        char[] arr = Integer.toString(num).toCharArray();
        int n = arr.length;
        int[] max = new int[n];
        max[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[max[i + 1]]){
                max[i] = i;
            }else{
                max[i] = max[i + 1];
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] < arr[max[i]]){
                char temp = arr[i];
                arr[i] = arr[max[i]];
                arr[max[i]] = temp;
                break;
            }
        }
        return Integer.parseInt(new String(arr));
        
        
    }
}

    