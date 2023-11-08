#include "inverted.h"

void file_validation(Flist **head, char *argv[])
{
	int i=1,empty;
	while(argv[i])
	{
		empty=isfileEmpty(argv[i]);
		if(empty == FILE_NOTAVAILABLE)
		{
			printf("File : %s is not avaialable\n",argv[i]);
			printf("Hence we are not adding this file into file linked list\n");
		}
		else if(empty == FILE_EMPTY)
		{
			printf("File : %s is not having content into it\n",argv[i]);
			printf("Hence we are not adding this file into file linked list\n");
		}
		else
		{
			int ret = create_list(head, argv[i]);
			if(ret == SUCCESS)
			{
				printf("SUCCESSFUL : Inserting the file name: %s file linked list\n", argv[i]);
			}
			else if(ret == REPETATION)
			{
				printf("File name : %s is already exist\n",argv[i]);
			}
			else
				printf("FAILURE\n");
		}
		i++;
	}
}

int isfileEmpty(char *filename)
{
	//opening the files
	FILE *fptr = fopen(filename,"r");
	if(fptr == NULL)
	{
		return FILE_NOTAVAILABLE;
	}

	//reading the content of file
	fseek(fptr,0,SEEK_END);
	if(ftell(fptr)==0)
		return FILE_EMPTY;
}
int create_list(Flist **head, char *file)
{
	//check whether filename is duplicate
	Flist *temp = *head;
	while(temp)
	{
		if(strcmp(temp->file_name,file)!= 0)
			temp=temp->link;
		else
			return REPETATION;
	}

	//create linked list
	Flist *new = malloc(sizeof(Flist));
	if(new == NULL)
		return FAILURE;
	strcpy(new->file_name,file);
	new->link=NULL;
	if(*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while(temp->link)
		{
			temp=temp->link;
		}
		temp->link = new;
	}
	return SUCCESS;
}
