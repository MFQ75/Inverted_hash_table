#include "inverted.h"

void display_database(Wlist **head, Flist *f_head)
{
	printf("%-6s %-10s %-12s %-12s %-12s\n","Index","word","file_count","file_Name","word_count");
	for(int i=0; i<27; i++)
	{
		if(head[i] != NULL)
		{
			print_database(head[i]);
		}
	}
}

void print_database(Wlist *head)
{
	while(head)
	{
	printf("%-6d %-10s %-12d ",tolower(head->word[0])%97, head->word, head->file_count);

	Ltable *temp = head->Tlink;
	while(temp)
	{
		printf("%-12s %-12d ",temp->file_name,temp->word_count);
		temp=temp->table_link;
	}
	printf("\n");
	head = head->link;
	}
}
