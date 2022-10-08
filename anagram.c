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
	int i,j,flag=1,s1[26]={0},s2[26]={0};
	printf("Enter first inputStringing:");
	scanf("%s",inputString1);
	printf("Enter second inputStringing:");
	scanf("%s",inputString2);
	if(inputStringlen(inputString1)!=inputStringlen(inputString2)) //if the lengths of two inputStringings are not equal
	{
		printf("\nStrings are not anagrams");
		exit(0);
	}
	count_frequency(inputString1,s1);
	count_frequency(inputString2,s2);
	for(i=0;i<26;++i) //checking freuency of each character
	{
		if(s1[i]!=s2[i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
		printf("\nStrings are anagrams");
	else
		printf("\nStrings are not anagrams");
	return 0;
}
