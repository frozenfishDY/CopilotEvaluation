/**https://leetcode.com/problems/equal-rational-numbers/ */
//Given two strings s and t, each of which represents a non-negative rational number, return true if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.
//A rational number can be represented using up to three parts: <IntegerPart>, <NonRepeatingPart>, and a <RepeatingPart>. The number will be represented in one of the following three ways:
//<IntegerPart>
//For example, 12, 0, and 123.
//<IntegerPart><.><NonRepeatingPart>
//For example, 0.5, 1., 2.12, and 123.0001.
//<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>
//For example, 0.1(6), 1.(9), 123.00(1212).
//The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets. For example:
//1/6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66).


bool isRationalEqual(char * s, char * t){
    int i = 0, j = 0;
    while(s[i] != '(' && s[i] != '\0') i++;
    while(t[j] != '(' && t[j] != '\0') j++;
    if(i == j && strncmp(s, t, i) == 0) return true;
    if(i == j && strncmp(s, t, i) != 0) return false;
    if(i != j) return false;
    int k = i + 1, l = j + 1;
    while(s[k] != ')') k++;
    while(t[l] != ')') l++;
    if(k - i != l - j) return false;
    int m = k + 1, n = l + 1;
    while(s[m] != '\0') m++;
    while(t[n] != '\0') n++;
    if(m - k != n - l) return false;
    int a = k - i - 1, b = l - j - 1;
    int c = m - k - 1, d = n - l - 1;
    if(a * d != b * c) return false;
    char* s1 = (char*)malloc(sizeof(char) * (a + 1));
    char* s2 = (char*)malloc(sizeof(char) * (b + 1));
    char* t1 = (char*)malloc(sizeof(char) * (c + 1));
    char* t2 = (char*)malloc(sizeof(char) * (d + 1));
    strncpy(s1, s + i + 1, a);
    strncpy(s2, s + k + 1, c);
    strncpy(t1, t + j + 1, b);
    strncpy(t2, t + l + 1, d);
    s1[a] = '\0';
    s2[c] = '\0';
    t1[b] = '\0';
    t2[d] = '\0';
    char* s3 = (char*)malloc(sizeof(char) * (a + c + 1));
    char* t3 = (char*)malloc(sizeof(char) * (b + d + 1));
    strcpy(s3, s1);
    strcat(s3, s2);
    strcpy(t3, t1);
    strcat(t3, t2);
    if(strcmp(s3, t3) == 0) return true;
    return false;

}

    