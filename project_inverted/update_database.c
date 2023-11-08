#include "inverted.h"

int update_database(Wlist **head, Flist *f_head)
{
	printf("Enter the file name : ");
	char filename[FNAME_SIZE];
	scanf("%s",filename);

	FILE *fptr = fopen(filename,"r");
	if(fptr == NULL)
	{
		perror("file");
		return FAILURE;
	}

	char buffer[100];
	while(fscanf(fptr, "%s", buffer) > 0)
	{
		if(buffer[0] != '#')
		{
			return FAILURE;
		}
		int index = atoi(strtok(buffer,"#;"));
		char *word = strtok(NULL,";");
		
		int filecount = atoi(strtok(NULL,";"));
		char *filename = strtok(NULL,";");
		int wordcount = atoi(strtok(NULL,";"));
	        if(index > 0 && index > 25)
		index = 26;	
	        insert(&head[index],word,filename,filecount,wordcount);
		for(int i=1; i<filecount; i++)
		{
		        filename = strtok(NULL,";");
		        wordcount = atoi(strtok(NULL,";"));
	                link(&head[index],filename,wordcount);

		}

	}
		return SUCCESS;
}

int insert(Wlist *head[],char *word,char *filename,int filecount,int wordcount)
{
	//creating a node of Wlist
	Wlist *new = malloc(sizeof(Wlist));
	if(new == NULL)
		return FAILURE;
	//updating the value
	new->file_count =filecount;
	strcpy(new->word,word);
	new->Tlink = NULL;
	new->link = NULL;

	//updating the table link
	link(&new,filename,wordcount);

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

int link(Wlist **head,char *filename,int wordcount)
{
	//creating the node for table link
	Ltable *new = malloc(sizeof(Ltable));
	if(new == NULL)
		return FAILURE;

	new->word_count	= wordcount;
	strcpy(new->file_name,filename);
	
	new->table_link = NULL;
	
	if((*head)->Tlink == NULL)
	(*head)->Tlink = new;
	else
	{
		Ltable *temp = (*head)->Tlink;
		while(temp->table_link)
			temp = temp->table_link;
		temp->table_link = new;
	}
	return SUCCESS;
}
