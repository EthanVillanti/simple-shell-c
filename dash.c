// Shell Program
// CS 4348.003: Operating Systems
// Programmers: Ethan Villanti and Remnin Ezekiel Ferrer
// This is a simple shell program that has two modes, Interactive and Batch.
// Interactive processes commands entered by the user and will termninate with "exit".
// Batch processes commands from a given text file and terminates at the end of file.
// To access Interactive, enter "./dash". For Batch, enter "./dash <filename.txt>".
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
// Indefinite while loop that reads in lines given by user
void interactiveMode(){
  
   while(1){ // Run indefinitely, only stops with exit
 	char line[100];
 	printf("dash> ");
 	fgets(line, 100, stdin);
 	
 	//int pid = fork();
 	
 	if(strstr(line,"><")){
   	//redirect
 	}
 	if(strstr(line,"&")){
   	// parallel
 	}
 	//if(pid == 0){
   	// Checks for built-in commands first
   	if(strcmp(line,"exit\n") == 0){
     	exit(0);
   	}
   	else if(strstr(line,"path") != NULL){
     	printf("path built-in\n");
   	}
   	else if(strstr(line,"cd") != NULL){
     	printf("cd\n");
   	}
   	else{
     	char *tokenedLine[50];     	
     	
     	char* piece = strtok(line, " ");
     	int i = 0;
     	
     	// Stores tokenized pieces into an array
     	while(piece != NULL){
       	tokenedLine[i++] = piece;
       	piece = strtok(NULL, " ");
     	}
     	// Combines the command with /bin/ to find command path
     	strcat(path, tokenedLine[0]);
     	printf("%s", path);
     	
     	//Call fork function
     	execvp(tokenedLine[0], tokenedLine);
   	}
   	exit(0); // Exit Child
 	//}
 	// Parent
	// else{
   	//int w = wait(NULL);
 	//} 
   }
}
 
// Reads in lines from file name given by command line
void batchMode(char fileName[]){
	FILE *fp = fopen(fileName,"r");
	if(fp == NULL){
  	perror("Unable to open file! (make sure to add .txt!)");
  	exit(1);
	}
	
	char *line = NULL;
	size_t len = 0;
	
	while(getline(&line, &len, fp) != -1){
  	// print out the line
  	fputs(line, stdout);
  	// Checks for built-in commands first
  	// Checks for built-in commands first
 	if(strcmp(line,"exit\n") == 0){
   	exit(0);
 	}
 	else if(strstr(line,"path") != NULL){
   	printf("path\n");
 	}
 	else if(strstr(line,"ls") != NULL){
   	
 	}
	}
}
// Main that reads command lines, checks if we go to interactive or batch
int main(int argc, char *argv[]){
 
 // If there is no input, start interactive mode
 if(argc == 1){
 	interactiveMode(argc, argv);  
 }
 // Otherwise, execute batch mode
 else{
   batchMode(argv[1]);  
 }
  return 0;
}
