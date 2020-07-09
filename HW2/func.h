#ifndef FUNC_H_
#define  FUNC_H_
#define  MAX_LEN	      100

void initString(char* str,int size);
void printString(const char *str);
int countWords(char *str);
void longestInCapital(char *str);
void revertWords(char * str);
void eraseCharsFromString (char *str, const char *symbols);
int isPalindrome(const char *str);
void reversOneWord(int countWord, char* str, char* word);
int findDelimiter(char x);
void toUpper(int maxString, char* pMaxString);


#endif // !FUNC_H_
