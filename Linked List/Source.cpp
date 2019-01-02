#include <stdio.h>
#include <string.h>
#include <conio.h>// ספריה למחיקת מסך
#include <stdlib.h> // atoi , בחירה אוטומטית של מספרים rand
#include <time.h> //ספריה להרוס שעון srand
#include <ctype.h> //
#define size 100
#define col 30
#define row 10

typedef struct node {
	char name[255];
	int id;
	struct node *next;
}node;

node * makenode(char name[], int id)
{
	node *temp = (node*)malloc(sizeof(node));
	if (!temp)
		return NULL;
	strcpy_s(temp->name, name);
	temp->id = id;
	temp->next = NULL;
	return temp;
}

node * func(node *head, node *temp)
{
	node *current = head;

	if (temp->id < head->id)		//put the temp in the start
	{
		temp->next = head;
		head = temp;
		return head;
	}

	while (current->next != NULL)	//put the temp in the middle
	{
		if (current->id < temp->id && (current->next)->id>temp->id)
		{
			temp->next = current->next;
			current->next = temp;
			return temp;
		}
		current = current->next;
	}
	if (temp->id > current->id)		//put the temp in the end
		current->next = temp;
	return head;
}

void main()
{
	node *temp, *head;
	char arr[255];
	int id, i;

	printf("enter name: ");
	gets_s(arr);
	printf("enter id: ");
	scanf_s("%d", &id);
	head = makenode(arr, id);

	for (i = 0; i < 2; i++)
	{
		printf("enter name: ");
		gets_s(arr);
		getchar();
		printf("enter id: ");
		getchar();
		scanf_s("%d", &id);

		temp = makenode(arr, id);
		head = func(head, temp);
	}
	

	while (head)
	{
		puts(head->name);
		printf("%d", head->id);
		head = head->next;
	}

	getchar(); getchar();
}
