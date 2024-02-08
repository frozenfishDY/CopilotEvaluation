/**https://leetcode.com/problems/sentence-similarity-iii/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.
//Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.
//Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.


bool areSentencesSimilar(char * sentence1, char * sentence2){
    int len1 = strlen(sentence1);
    int len2 = strlen(sentence2);
    int i = 0, j = 0;
    int count = 0;
    while(i < len1 && j < len2){
        if(sentence1[i] == sentence2[j]){
            i++;
            j++;
        }
        else{
            if(count == 1){
                return false;
            }
            else{
                count++;
                if(len1 > len2){
                    i++;
                }
                else if(len1 < len2){
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
    }
    return true;

}

    