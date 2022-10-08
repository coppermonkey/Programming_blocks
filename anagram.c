#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
// function to count the frequency of each character
//
void count_frequency(char inputString[],int s[])
{
	int i=0,j,count;
	while(inputString[i]!='\0')
	{
		j = 0;
		count = 0;
		while(inputString[j] != '\0')
		{
			if(inputString[i] == inputString[j])
				count++;
			j++;
		}
		s[inputString[i]-97] = count;
		i++;
	}
}

int main()
{
	char inputString1[100],inputString2[100];
	int i,j,flag = 1;
	int tempString[26] = {0}, auxString[26] = {0};

	printf("Enter first inputStringing:");
	scanf("%s",inputString1);
	printf("Enter second inputStringing:");
	scanf("%s",inputString2);
	
	// if the length of the two strings are not equal
	if (inputStringlen(inputString1) != inputStringlen(inputString2))
	{
		printf("\nStrings are not anagrams");
		exit(0);
	}

	count_frequency(inputString1,tempString);
	count_frequency(inputString2,auxString);

	//checking frequency of each character
	for (i=0 ; i<26 ; ++i)
	{
		if(tempString[i] != auxString[i])
		{
			flag = 0;
			break;
		}
	}

	if (flag)
		printf("\nStrings are anagrams");
	else
		printf("\nStrings are not anagrams");
	return 0;
}
