/**https://leetcode.com/problems/rearrange-spaces-between-words/ */
//You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.
//Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
//Return the string after rearranging the spaces.
// 
//Example 1:
//Input: text = "  this   is  a sentence "
//Output: "this   is   a   sentence"
//Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
//Example 2:
//Input: text = " practice   makes   perfect"
//Output: "practice   makes   perfect "
//Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
// 
//Constraints:
//	1 <= text.length <= 100
//	text consists of lowercase English letters and ' '.
//	text contains at least one word.
char * reorderSpaces(char * text){
int i,j=0,k=0,l=0,m=0,n=0;
    for(i=0;i<strlen(text);i++){
        if(text[i]==' ')
            k++;
    }
    char *temp = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    for(i=0;i<strlen(text);i++){
        if(text[i]!=' '){
            temp[j]=text[i];
            j++;
        }
        else{
            if(text[i+1]!=' '){
                temp[j]=' ';
                j++;
            }
            else
                continue;
        }
    }
    temp[j]='\0';
    char *result = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if(k==0){
        for(i=0;i<strlen(text);i++){
            result[i]=text[i];
        }
        result[i]='\0';
        return result;
    }
    else if(j==1){
        for(i=0;i<strlen(text);i++){
            if(text[i]!=' '){
                result[i]=text[i];
            }
            else
                break;
        }
        result[i]='\0';
        for(i=0;i<k;i++){
            strcat(result," ");
        }
        return result;
    }
    else{
        for(i=0;i<strlen(temp);i++){
            if(temp[i]==' ')
                l++;
        }
        m=l/(j-1);
        n=l%(j-1);
        for(i=0;i<j-1;i++){
            result[i]=temp[i];
            for(int p=0;p<m;p++){
                strcat(result," ");
            }
        }
        result[i]='\0';
        for(i=0;i<n;i++){
            strcat(result," ");
        }
        return result;
    }
}