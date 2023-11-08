a.out: create_database.o display_database.o save.o file_list.o main.o update_database.o search.o
	gcc -o a.out create_database.o display_database.o save.o file_list.o main.o update_database.o search.o
main.o: main.c 
	gcc -c main.c 
create_database.o: create_database.c 
	gcc -c create_database.c
display_database.o: display_database.c 	
	gcc -c display_database.c
save.o: save.c 
	gcc -c save.c 
file_list.o: file_list.c 
	gcc -c file_list.c
update_database.o: update_database.c
	gcc -c update_database.c 
search.o: search.c
	gcc -c search.c
clean:
	rm *.out *.o


