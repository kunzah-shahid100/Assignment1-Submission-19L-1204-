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
	int number, number1, number2;
	char Rollno[10];
	char Name[50];
	char Email[50];
	char filename[50];
	char c[1000];
	FILE* fptr;
	FILE* fptr1;
	char holder;
	int line;
	int desiredLine;
	bool characters;
	printf("Enter number from 1-3 to do actions stated: ");
	printf("1. Add student.");
	printf("2. Read record of any student.");
	printf("3. Delete record of any student.");
	scanf("%d", &number); //Take input from the user
	
	if (number == 1)
	{
		printf("Write Name of the student");
		scanf("%s", &Name); //Take name from the user
		printf("Write Rollno of the student");
		scanf("%s", &Rollno); //Take rollno from the user
		printf("Write Email-ID of the student");
		scanf("%s", &Email); //Take email-ID from the user
		fptr = (fopen(filename, "r"));
		fptr1 = fopen(filename, "a");
		if (fptr == 0)
		{
			printf("ERROR!\n");
			printf("Unable to open file.\n");
		}
		else
		{
			fprintf(fptr1, "%s", Name);
			fprintf(fptr1, ", %s", Rollno);
			fprintf(fptr1, ", %s", Email);
		}

	}
	else if (number == 2)
	{
		printf("Enter a number to read the record of a specific student: ");
		scanf("%d", &number1); //Take input from the user
		if (number1 == 0)
		{
			fptr = (fopen(filename, "r"));
			if (fptr == 0)
			{
				printf("ERROR!\n");
				printf("Unable to open file.\n");
			}
			else
			{
				// reads text until newline is encountered
				fscanf(fptr, "%[^\n]", c);
				printf("Data from the file:\n%s", c);
			}

			fclose(fptr);
		}
		else
		{
			fptr = (fopen(filename, "r"));
			if (fptr == 0)
			{
				printf("ERROR!\n");
				printf("Unable to open file.\n");
			}
			else
			{
				while (1)
				{
					desiredLine = number1; //reads only desired line
					line = 1;
					holder = fgetc(fptr);
					if (holder == EOF)
					{
						break;
					}
					else if (holder == '\n')
					{
						++line;
						if (desiredLine == line)
						{
							characters = true;
						}
						else if (characters)
						{
							break;
						}
					}
					else if (characters)
					{
						putchar(holder);
					}
				}
			}
			fclose(fptr);
		}
	}
	else
	{
		printf("Enter a number to delete the record of a specific student: ");
		scanf("%d", &number2); //Take input from the user
		if (number1 == 0)
		{
			fptr = (fopen(filename, "r"));
			if (fptr == 0)
			{
				printf("ERROR!\n");
				printf("Unable to open file.\n");
			}
			else
			{
				
			}

			fclose(fptr);
		}
		else
		{
			fptr = (fopen(filename, "r"));
			if (fptr == 0)
			{
				printf("ERROR!\n");
				printf("Unable to open file.\n");
			}
			else
			{

			}

			fclose(fptr);
		}
	}

	return 0;
}
