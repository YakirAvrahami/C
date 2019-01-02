#include <stdio.h>
#include <string.h>
#include <conio.h>// for 'cls'
#include <stdlib.h> // atoi , rand , malloc
#include <time.h> // srand
#include <ctype.h> 
#define size 100
#define col 30
#define row 10



typedef struct classNode {
	char name[200];
	int id;
	struct classNode *next;
}classNode;

classNode * makeNode(char name[], int id)
{
	classNode *temp = (classNode*)malloc(sizeof(classNode));
	if (!temp)
		return NULL;
	strcpy_s(temp->name, name);
	temp->id = id;
	temp->next = NULL;
	return temp;
}

classNode * func(classNode *head, classNode *temp)
{
	classNode *current = head;

		//put the temp in the start
	if (temp->id < head->id)		
	{
		temp->next = head;
		head = temp;
		return head;
	}

		//put the temp in the middle
	while (current->next != NULL)	
	{
		if (current->id < temp->id && (current->next)->id>temp->id)
		{
			temp->next = current->next;
			current->next = temp;
			return head;
		}
		current = current->next;
	}

		//put the temp in the end
	if (temp->id > current->id)		
		current->next = temp;
	return head;
}

void main()
{
	classNode *temp, *head;
	char name[200];
	int id, i,j=1;

	printf("enter name: ");
	gets_s(name);
	printf("enter id: ");
	scanf_s("%d", &id);
	head = makeNode(name, id);

	for (i = 0; i < 3; i++)
	{
		printf("enter name: ");
		getchar();
		gets_s(name);
		printf("enter id: ");
		scanf_s("%d", &id);

		temp = makeNode(name, id);
		head = func(head, temp);
	}
	

	while (head)
	{
		printf("\nindex %d:\n", j);
		printf("\t--------\n");
		printf("\tname: ");
		puts(head->name);
		printf("\tid: %d\n", head->id);
		printf("\t--------\n");
		head = head->next;
		j++;
	}

	getchar(); getchar();
}
