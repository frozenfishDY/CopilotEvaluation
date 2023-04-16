/**https://leetcode.com/problems/cinema-seat-allocation/ */
//A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.
//Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.
//Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.


int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int i, j, k, count = 0, *arr = malloc(100000 * sizeof(int));
    for(i = 0; i < reservedSeatsSize; i++){
        arr[reservedSeats[i][0] * 10 + reservedSeats[i][1]] = 1;
    }
    for(i = 1; i <= n; i++){
        if(arr[i * 10 + 2] == 0 && arr[i * 10 + 3] == 0 && arr[i * 10 + 4] == 0 && arr[i * 10 + 5] == 0){
            count++;
            arr[i * 10 + 2] = 1;
            arr[i * 10 + 3] = 1;
            arr[i * 10 + 4] = 1;
            arr[i * 10 + 5] = 1;
        }
        if(arr[i * 10 + 6] == 0 && arr[i * 10 + 7] == 0 && arr[i * 10 + 8] == 0 && arr[i * 10 + 9] == 0){
            count++;
            arr[i * 10 + 6] = 1;
            arr[i * 10 + 7] = 1;
            arr[i * 10 + 8] = 1;
            arr[i * 10 + 9] = 1;
        }
        if(arr[i * 10 + 4] == 0 && arr[i * 10 + 5] == 0 && arr[i * 10 + 6] == 0 && arr[i * 10 + 7] == 0){
            count++;
            arr[i * 10 + 4] = 1;
            arr[i * 10 + 5] = 1;
            arr[i * 10 + 6] = 1;
            arr[i * 10 + 7] = 1;
        }
    }
    return count;

}

    