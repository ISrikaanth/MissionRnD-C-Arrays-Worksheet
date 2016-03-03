/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K)
{
	if ((students == NULL) || (len <= 0) || (K > len)||(K<=0))
		return NULL;
	struct student *result;
	result = (struct student *)malloc(10*sizeof(struct student));
	int i = 0, max, pos = 0,j,p;
	p = K;
	for (i = 0; i < len; i++)
	{
		max = students[i].score;
		pos = i;
		for (j = i + 1; j < len; j++)
		{
			if ((students[j].score) > max)
			{
				max = students[j].score;
				pos = j;
			}
		}
		result[p-1].name = students[pos].name;
		result[p-1].score = students[pos].score;
		p--;
		if (p == 0)
			break;
	}
	return &result;
}