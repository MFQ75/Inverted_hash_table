#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FAILURE -1
#define SUCCESS 0
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE  -3
#define REPETATION -4

//structure for file
typedef char data_t;
typedef struct file_node
{
	data_t file_name[FNAME_SIZE];
	struct file_node *link;
}Flist;

//stucture for link table
typedef struct linktable_node
{
	int word_count;
	data_t file_name[FNAME_SIZE];
	struct linktable_node *table_link;
}Ltable;
typedef struct word_node
{
	int file_count;
	data_t word[WORD_SIZE];
	Ltable *Tlink;
	struct word_node *link;
}Wlist;
//file validation function prototype
void file_validation(Flist **head, char *argv[]);
int isfileEmpty(char *filename);
int create_list(Flist **head, char *file);

//create_data function prototype
void create_database(Flist *f_head, Wlist *head[]);
Wlist *read_datafile(Flist *f_head, Wlist *head[]);
int table_link(Wlist **head,char *filename);
int insert_at_last(Wlist *head[],char *word,char *filename);
int update_word_count(Wlist *head, char *filename);

//display_database function prototype
void display_database(Wlist **head, Flist *f_head);
void print_database(Wlist *head);

//Update_database function prototype
int update_database(Wlist **head, Flist *f_head);

//search function prototype
void search_database(Wlist *head, char *word);

//save function prototype
void copy_data(Wlist *head,FILE *file);
void save_database(Wlist *head[]);

int insert(Wlist *head[],char *word,char *filename,int filecount,int wordcount);
int link(Wlist **head,char *filename,int wordcount);
#endif
