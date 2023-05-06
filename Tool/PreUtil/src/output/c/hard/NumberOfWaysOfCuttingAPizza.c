/**https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/ */
//Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 
//For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.
//Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.


int ways(char ** pizza, int pizzaSize, int k){
    int i,j;
    int** arr = (int**)malloc(sizeof(int*)*pizzaSize);
    for(i=0;i<pizzaSize;i++){
        arr[i] = (int*)malloc(sizeof(int)*pizzaSize);
    }
    for(i=0;i<pizzaSize;i++){
        for(j=0;j<pizzaSize;j++){
            arr[i][j] = 0;
        }
    }
    for(i=0;i<pizzaSize;i++){
        for(j=0;j<pizzaSize;j++){
            if(pizza[i][j] == 'A'){
                arr[i][j] = 1;
            }
        }
    }
    int** arr2 = (int**)malloc(sizeof(int*)*pizzaSize);
    for(i=0;i<pizzaSize;i++){
        arr2[i] = (int*)malloc(sizeof(int)*pizzaSize);
    }
    for(i=0;i<pizzaSize;i++){
        for(j=0;j<pizzaSize;j++){
            arr2[i][j] = 0;
        }
    }
    for(i=0;i<k-1;i++){
        for(j=0;j<pizzaSize;j++){
            for(int l=0;l<pizzaSize;l++){
                if(arr[j][l] == 1){
                    for(int m=j+1;m<pizzaSize;m++){
                        if(arr[m][l] == 1){
                            arr2[j][l] = (arr2[j][l] + arr[m][l])%1000000007;
                        }
                    }
                    for(int m=l+1;m<pizzaSize;m++){
                        if(arr[j][m] == 1){
                            arr2[j][l] = (arr2[j][l] + arr[j][m])%1000000007;
                        }
                    }
                }
            }
        }
        for(j=0;j<pizzaSize;j++){
            for(int l=0;l<pizzaSize;l++){
                arr[j][l] = arr2[j][l];
                arr2[j][l] = 0;
            }
        }
    }
    int sum = 0;
    for(i=0;i<pizzaSize;i++){
        for(j=0;j<pizzaSize;j++){
            sum = (sum + arr[i][j])%1000000007;
        }
    }
    return sum;

}

    