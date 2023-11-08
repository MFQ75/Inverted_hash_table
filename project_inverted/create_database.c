#include "inverted.h"

char *fname;
//creating the database
void create_database(Flist *f_head, Wlist *head[])
{
	
	while(f_head)
	{
		read_datafile(f_head,head);
		fname=f_head->file_name;
		f_head = f_head->link;
	}
}	

Wlist *read_datafile(Flist *f_head, Wlist *head[])
{
	//opening the file
	FILE *fptr = fopen(f_head->file_name,"r");

	//read the word by word from file
	char word[WORD_SIZE];
	while(fscanf(fptr, "%s", word) != EOF)
	{
		int index = tolower(word[0])%97;

		if(index >= 0 && index >= 25)
			index = 26;
		int flag = 1;
		Wlist *temp = head[index];
		while(temp)
		{
			//checking whether the same is repeted
			if(!strcmp(temp->word,word))
			{
				printf("%s\n",temp->word);
				update_word_count(temp,f_head->file_name);
				flag = 0;
			}
			temp= temp->link;
		}
		if(flag)
			insert_at_last(&head[index],word,f_head->file_name);


	}
}
int update_word_count(Wlist *head, char *filename)
{
	Ltable *temp = head->Tlink;
	while(temp->table_link)
	{
		if(!strcmp(temp->file_name,filename))
		{
			(temp->word_count)++;
			return SUCCESS;
		}
		temp = temp->table_link;
	}
	if(!strcmp(temp->file_name,filename))
	{
		(temp->word_count)++;
		return SUCCESS;
	}
	
	Ltable *new = malloc(sizeof(Ltable));
	if(new == NULL)
		return FAILURE;

	new->word_count	= 1;
	strcpy(new->file_name,filename);
	new->table_link = NULL;
        temp->table_link= new;	
	(head->file_count)++;
}

int insert_at_last(Wlist *head[],char *word,char *filename)
{
	//creating a node of Wlist
	Wlist *new = malloc(sizeof(Wlist));
	if(new == NULL)
		return FAILURE;
	//updating the value
	new->file_count =1;
	strcpy(new->word,word);
	new->Tlink = NULL;
	new->link = NULL;

	//updating the table link
	table_link(&new,filename);

	if(*head == NULL)
		*head = new;
	else
	{
		Wlist *temp = *head;
		while(temp->link)
			temp = temp->link;

		temp->link = new;
	}
	return SUCCESS;
}

int table_link(Wlist **head,char *filename)
{
	//creating the node for table link
	Ltable *new = malloc(sizeof(Ltable));
	if(new == NULL)
		return FAILURE;

	new->word_count	= 1;
	strcpy(new->file_name,filename);
	new->table_link = NULL;

	(*head)->Tlink = new;
	return SUCCESS;
}

