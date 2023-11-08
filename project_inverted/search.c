#include "inverted.h"

void search_database(Wlist *head, char *word)
{
	while(head)
	{
		if(!strcmp(head->word,word))
		{
			printf("Word %s is found in %d file\n",word,head->file_count);
			Ltable *temp=head->Tlink;
			while(temp)
			{
				printf("In %s it is present %d times\n",temp->file_name,temp->word_count);
				temp = temp->table_link;
			}
			return ;
		}
		head = head->link;
	}
	printf("Not Found\n");
}
