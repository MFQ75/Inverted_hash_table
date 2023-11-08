#include "inverted.h"
/*
Name : Md Faizan Quamar
Date : 27-08-2023
Project: Inverted search
*/
int main(int argc, char *argv[])
{
	//validate CLA
	if(argc>1)
	{
		//create the list of filename
		Flist *f_head = NULL;
		Wlist *head[27]={NULL};
		//validate the file
		file_validation(&f_head,argv);
		if(f_head == NULL)
		{
			printf("Program terminated\n");
		}
		else
		{
			int flag =1;
			char ch;
			do
			{
				printf("1.Create Database\n2.Display Database\n3.Update Database\n4.Search\n5.Save Database\nEnter the choice : ");
				int num;
				scanf("%d",&num);
				switch(num)
				{
					case 1 :if(flag == 1)
						{
							create_database(f_head,head);
							printf("Create data base successfully completed\n");
							flag = 0;
						}
						else if(flag == 2)
						{
							printf("Already updated the data. so, create data base not possible\n"); 
						}
						else
							printf("Create data base already completed\n");
						break;
					case 2 :display_database(head,f_head);
						break;
					case 3 :if(flag)
						{
							if(update_database(head,f_head) != FAILURE)
							{
								printf("Update data Successfull\n");
								flag = 2;
							}
						}
						else
							printf("Already created the data base\n");
						break;
					case 4 :printf("Enter the word you want to search\n");
						char word[20];
						scanf("%s",word);
						int index = tolower(word[0])%97;
						if(index >= 0 && index >= 25)
							index = 26;
						search_database(head[index],word);
						break;
					case 5 :save_database(head);
						break;
					default:printf("Invalid Input\n");
				}
				printf("Do you want to continue\n");
				printf("Enter y/Y to continue and n/N to exit\n");
				scanf(" %c",&ch);
			}while(ch == 'Y' || ch == 'y');
		}
	}
	else
	{
		printf("Enter valid number of arguments\n");
		printf("./a.out f1.txt f2.txt ......\n");
	}
}
