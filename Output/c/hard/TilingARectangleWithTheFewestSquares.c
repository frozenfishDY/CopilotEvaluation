/**https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/ */
//Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.


int tilingRectangle(int n, int m){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++){
        arr4[i] = 0;
    }
    int ans = 0;
    int flag = 0;
    while(flag==0){
        flag = 1;
        for(i=0;i<n;i++){
            if(arr[i]<m){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            break;
        }
        for(i=0;i<n;i++){
            if(arr[i]<m){
                arr[i]++;
                arr2[i]++;
                break;
            }
        }
        for(i=0;i<m;i++){
            if(arr3[i]<n){
                arr3[i]++;
                arr4[i]++;
                break;
            }
        }
        ans++;
    }
    return ans;

}

    