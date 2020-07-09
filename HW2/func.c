#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "func.h"
const char* SPECIAL_CHARACTERS = { " ,:?-!" };
void initString(char* str, int size)
{
	printf("Please Enter String\n");
	getchar();
	if (str != NULL && size > 0)
	{
		if (fgets(str, size, stdin))
		{
			str[strcspn(str, "\n")] = '\0';
		}
	}
}
void printString(const char *str)
{
	printf("Your String is:\n");
	puts(str);
}
int countWords(char *str)
{
	char temp[MAX_LEN];
	char* words;
	int numOfWords = 0;
	strcpy(temp, str);
	words = strtok(temp, SPECIAL_CHARACTERS);
	while (words)
	{
		words = strtok(NULL, SPECIAL_CHARACTERS);
		numOfWords++;

	}
	return numOfWords;
}

int findDelimiter(char x)
{
	for (int i = 0; i < strlen(SPECIAL_CHARACTERS); i++)
	{
		if (x == SPECIAL_CHARACTERS[i])
			return 1;
	}
	return 0;

}
void longestInCapital(char *str)
{
	int countChar = 0;
	int maxString = 0;
	char* pMaxString = str;
	for (int i = 0; i <= strlen(str); i++)
	{
		if ((findDelimiter(str[i])) || (str[i] == '\0'))
		{
			if (countChar > maxString)
			{
				pMaxString = (&str[i] - countChar);
				maxString = countChar;

			}
			countChar = 0;
		}
		else
		{
			countChar++;
		}
	}
	toUpper(maxString, pMaxString);
	}
void toUpper(int maxString , char* pMaxString){

	for (int j = 0; j < maxString; j++)
	{
		*pMaxString = toupper(*pMaxString);
		pMaxString++;
	}

}
void revertWords(char *str) {
	char word[MAX_LEN];
	int j = 0;
	int countChar = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (findDelimiter(str[i]))
		{
			reversOneWord(countChar, &str[(i-countChar-1)], word);
			str[i] = '*';
			j = 0;
			countChar = 0;
		}
		else
		{
			countChar++;
			word[j] = str[i];
			j++;
		}
	}
}
void reversOneWord(int countWord, char* str , char* word)
{
	int j = 0;
	for (int i = countWord; i >0 ; i--,j++)
	{
		str[i] = word[j];
	}
}
void eraseCharsFromString(char *str, const char *symbols)
{
	char temp[MAX_LEN];
	strcpy(temp, str);
	memset(str, 0, sizeof(str[0]));
	char *words = strtok(temp, symbols);
	while (words)
	{	strcat(str, words);
	 words = strtok(NULL, symbols);
	}

}
int isPalindrome(const char *str)
{
	char temp[MAX_LEN];
	strcpy(temp, str);
	toUpper(strlen(temp), temp);
	char* pBegin = temp;
	char* pEnd = &temp[(strlen(temp) - 1)];
	while (pBegin < pEnd)
	{
		if(!(isalpha(*pBegin)))
		{
			pBegin++;
			continue;
		}
		if (!(isalpha(*pEnd)))
		{
			pEnd--;
			continue;
		}
		if (*pBegin != *pEnd)
		{
			return 0;
		}
		pBegin++;
		pEnd--;
	}
	return 1;
}
