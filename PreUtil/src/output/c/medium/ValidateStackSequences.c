/**https://leetcode.com/problems/validate-stack-sequences/ */
//Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int* stack = (int*)malloc(sizeof(int) * pushedSize);
    int top = -1;
    int index = 0;
    for(int i = 0; i < pushedSize; i++){
        stack[++top] = pushed[i];
        while(top >= 0 && stack[top] == popped[index]){
            top--;
            index++;
        }
    }
    return top == -1;

}

    