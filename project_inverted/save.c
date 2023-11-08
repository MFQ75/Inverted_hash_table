#include "inverted.h"

void save_database(Wlist *head[])
{
	printf("Enter the file name : ");
	char filename[FNAME_SIZE];
	scanf("%s",filename);

	FILE *fptr = fopen(filename,"w");
	if(fptr == NULL)
	{
		perror("file");
		return ;
	}
	for (int i=0; i<27; i++)
	{
		if(head[i] != NULL)
		{
			copy_data(head[i],fptr);
		}
	}
	fclose(fptr);
}

void copy_data(Wlist *head,FILE *file)
{
	while(head)
	{
		fprintf(file,"#%d;%s;%d;", tolower(head->word[0])%97, head->word, head->file_count);
		Ltable *temp = head->Tlink;
		while(temp)
		{
			fprintf(file, "%s;%d;", temp->file_name, temp->word_count);
			temp = temp->table_link;
		}
		char ch = '\n';
	        fprintf(file,"%c",ch);
		head = head->link;
	}
}
