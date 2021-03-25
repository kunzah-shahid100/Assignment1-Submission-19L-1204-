#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int countOccurrences(FILE* fptr, const char* filename, char* string)
{
	char fileString[1000]; //Pointer to an array of chars where the string read is copied.
	int count = 0;
	//Read until the end of file is reached
	while ((fgets(fileString, 1000, fptr)) != NULL)
	{
		//Check if string occurs in the char array, fileString
		if ((strstr(fileString, string)) != NULL)
		{
			count++; //Increment the count
		}
	}
	return count;
}

int main()
{
	int count = 0;
	char string[50];
	char filename[50];
	FILE* fptr;
	printf("Enter the filename you want to search: ");
	scanf("%s", &filename); //Take filename from the user
	printf("Enter word to search in file: ");
	scanf("%s", &string); //Take the word or key from the user

	fptr = (fopen(filename, "r"));
	if (fptr == 0)
	{
		printf("ERROR!\n");
		printf("Unable to open file.\n");
	}
	else
	{
		count = countOccurrences(fptr, filename, string);
	}

	printf("The number of occurrences of the word entered in the file are: ");
	printf("Number = %d", count);

	fclose(fptr);

	return 0;
}
