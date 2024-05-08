//Final Group Project
//Jake Castanon
//Dominic Rivera

#include <stdio.h>

#define FILENAME 100

//MENUS

void menu1(){
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	printf("\nChoose from one of the options above: ");
}

void menu2(){
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	printf("\nChoose from one of the options above: ");
}
//SAVE IMAGE

int saveImage(int* left, int* right, int* top, int* bot, int checker, int *row, int *col, int array[*row][*col]);

//DISPLAY IMAGE

int display(int *row, int *col, int array[*row][*col]);

//GET ROWS COLS

int getRowCol(char str[], int *row, int *col);

//LOAD IMAGE

int loadImage(char str[], int *row, int *col, int array[*row][*col]);

//CROP IMAGE

int crop(int* left, int* right, int* top, int* bot, int *row, int *col, int array[*row][*col]);

//DIM IMAGE

int dim(int *row, int *col, int array[*row][*col]);

//BRIGHTEN IMAGE

int brighten(int *row, int *col, int array[*row][*col]);

//ROTATE IMAGE

int rotate(int *row, int *col, int array[*row][*col]);

//MAIN

int main(){

	int breaking = 0;
	printf("\n");
	while(breaking == 0){
	//VARIABLES
		
		//
		char fileName[FILENAME];
		//
		int option1;
		int option2;
		char clear;
		int check = 0;
		menu1();
		scanf("%d", &option1);
		scanf("%c", &clear);
		if(option1 == 1){
		
			int fileRows = 0;
			int fileCols = 0;
			//char* loadfileName[FILENAME];
			getRowCol(fileName, &fileRows, &fileCols);
			//printf("\n%d %d", fileRows, fileCols);
			//printf("\n%s\n", fileName);
			int fileImg[fileRows][fileCols];
			loadImage(fileName, &fileRows, &fileCols, fileImg);
			
		while(breaking == 0){
			int option3;
			printf("\n");
			menu1();
			scanf("%d", &option3);
			scanf("%c", &clear);
		
			if(option3 == 1){
				
				int fileRows = 0;
				int fileCols = 0;
				//char* loadfileName[FILENAME];
				getRowCol(fileName, &fileRows, &fileCols);
				//printf("\n%d %d", fileRows, fileCols);
				//printf("\n%s\n", fileName);
				//int fileImg[fileRows][fileCols];
				loadImage(fileName, &fileRows, &fileCols, fileImg);

			}
			
			else if(option3 == 2){
				display(&fileRows, &fileCols, fileImg);
			}
			else if(option3 == 3){
				menu2();
				scanf("%d", &option2);
				scanf("%c", &clear);
				char choice;
				int saveCheck = 0;
				int left = 0;
				int right = 0;
				int top = 0;
				int bot = 0;
					if(option2 == 0){
						//LEAVE
					}
					if(option2 == 1){
						
						crop(&left, &right, &top, &bot, &fileRows, &fileCols, fileImg);
						saveCheck = saveCheck + 1;
						saveImage(&left, &right, &top, &bot, saveCheck, &fileRows, &fileCols, fileImg);
					}
					if(option2 == 2){
						dim(&fileRows, &fileCols, fileImg);
						saveCheck = saveCheck + 2;
						saveImage(&left, &right, &top, &bot, saveCheck, &fileRows, &fileCols, fileImg);
					}
					if(option2 == 3){
						brighten(&fileRows, &fileCols, fileImg);
						saveCheck = saveCheck + 3;
						saveImage(&left, &right, &top, &bot, saveCheck, &fileRows, &fileCols, fileImg);
					}/*
					if(option2 == 4){
						rotate(&fileRows, &fileCols, fileImg);
						saveCheck = saveCheck + 4;
						saveImage(&left, &right, &top, &bot, saveCheck, &fileRows, &fileCols, fileImg);
					}*/
					else{
						//LEAVE
					}
				
			}
			else{
				breaking++;
			}
		}
		
	/*IF*/	}
		
		else if(option1 == 2){
			printf("Sorry, no image to display\n");
		}
		else if(option1 == 3){
			printf("Sorry, no image to edit\n");
		}
		else if(option1 == 0){
			breaking++;
		}
		else{
			breaking++;
		}
		
	}
	return 0;
}

//DISPLAY IMAGE

int display(int *row, int *col, int array[*row][*col]){
	for(int i = 0; i < *row;i++){
		for(int j = 0; j < *col; j++){
			if(array[i][j] == 0){
				printf(" ");
			}
			if(array[i][j] == 1){
				printf(".");
			}
			if(array[i][j] == 2){
				printf("o");
			}
			if(array[i][j] == 3){
				printf("O");
			}
			if(array[i][j] == 4){
				printf("0");
			}
		}
		printf("\n");
	}
}

//ROTATE IMAGE

int rotate(int *row, int *col, int array[*row][*col]){
	for(int i = 0; i < *row;i++){
		for(int j = 0; j < *col; j++){
			if(array[j][i] == 0){
				printf(" ");
			}
			if(array[j][i] == 1){
				printf(".");
			}
			if(array[j][i] == 2){
				printf("o");
			}
			if(array[j][i] == 3){
				printf("O");
			}
			if(array[j][i] == 4){
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
//CROP IMAGE

int crop(int* left, int* right, int* top, int* bot, int *row, int *col, int array[*row][*col]){
	for(int i = 0; i < *row;i++){
		for(int j = 0; j < *col; j++){
			if(array[i][j] == 0){
				printf(" ");
			}
			if(array[i][j] == 1){
				printf(".");
			}
			if(array[i][j] == 2){
				printf("o");
			}
			if(array[i][j] == 3){
				printf("O");
			}
			if(array[i][j] == 4){
				printf("0");
			}
		}
		printf("\n");
	}
	printf("The image you want to crop is %d by %d.\n", *row, *col);
	printf("The row and column values start in the upper lefthand corner.\n");
	
	printf("\nWhich column do you want to be the new left side? ");
	scanf("%d", &*left);
	
	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &*right);
	
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &*top);
	
	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &*bot);
	
	for(int i = *top - 1; i <= *bot;i++){
		for(int j = *left - 1; j <= *right; j++){
			if(array[i][j] == 0){
				printf(" ");
			}
			if(array[i][j] == 1){
				printf(".");
			}
			if(array[i][j] == 2){
				printf("o");
			}
			if(array[i][j] == 3){
				printf("O");
			}
			if(array[i][j] == 4){
				printf("0");
			}
		}
		printf("\n");
	}
}
//GET ROWS COLS

int getRowCol(char str[],int *row, int *col){
	*row = *row - *row;
	*col = *col - *col;
	char fname[FILENAME];
	int s = 0;
	FILE *fp;
	char c;

	//GETING FILE AND STRING
	printf("What is the name of the image file? ");
	
	fgets(str, FILENAME, stdin);
	while(str[s] != '\n'){
		s++;
	}

	str[s] = '\0';
	
	//GETTING ROWS AND COLLUMNS
	fp = fopen(str, "r");
	if(fp == NULL){
		printf("Invalid file name.\n");
		return 1;
	}
	else{
		while(fscanf(fp, "%c", &c) == 1)
		{
			if(c == '\n'){
				*row = *row + 1;
			}
			//printf("%c", c);
			if(*row == 0){
				*col = *col + 1;
			}
		}
	}
	fclose(fp);
}
//LOAD IMAGE

int loadImage(char str[], int *row, int *col, int array[*row][*col]){
	
	FILE *fp;
	char c;
	int i = 0;
	int j = 0;

	fp = fopen(str, "r");
	
	//GETTING 2D ARRAY

	char imgTemp[*row][*col];
	
	while(fscanf(fp, "%c", &c) == 1)
	{
		if(c == '\n'){
			i++;
			j = 0;
		}
		else{
			imgTemp[i][j] = c;
			j++;
		}
	}

	for(int q = 0; q < *row;q++){
		for(int p = 0; p < *col; p++){
			if(imgTemp[q][p] == '0'){
				array[q][p] = 0;
			}
			if(imgTemp[q][p] == '1'){
				array[q][p] = 1;
			}
			if(imgTemp[q][p] == '2'){
				array[q][p] = 2;
			}
			if(imgTemp[q][p] == '3'){
				array[q][p] = 3;
			}
			if(imgTemp[q][p] == '4'){
				array[q][p] = 4;
			}
		}
	}

	
	fclose(fp);
	return 0;
}

//SAVE IMAGE

int saveImage(int* left, int* right, int* top, int* bot, int checker, int *row, int *col, int array[*row][*col]){
	//VARIABLES
	int choice;
	char clear1;
	FILE *fp;
	char fname[FILENAME];
	int s = 0;
	
	
	//DECIDE
	printf("Would you like to save your edited image?\n1. Yes\n2. No\nChoose an option: ");
	scanf("%d", &choice);
	scanf("%c", &clear1);
	
	//IFS AND WRITING
	if(choice == 1){
		printf("\nWhat is the name of the file you want to save to? ");
	
		fgets(fname, FILENAME, stdin);
		while(fname[s] != '\n'){
		s++;
		}
		fname[s] = '\0';
		fp = fopen(fname, "w");
		
		if(checker == 1){
			for(int i = *top; i <= *bot;i++){
				for(int j = *left; j <= *right; j++){
					fprintf(fp, "%d", array[i][j]);
				}
				fprintf(fp, "\n");
			}
		}
		if(checker == 2){
			for(int i = 0; i < *row;i++){
				for(int j = 0; j < *col; j++){
					if(array[i][j] <= 1){
						fprintf(fp,"%d", 0);
					}
					else{
						fprintf(fp,"%d", array[i][j] - 1);
					}
				}
				fprintf(fp, "\n");
			}
		}
		if(checker == 3){
			for(int i = 0; i < *row;i++){
				for(int j = 0; j < *col; j++){
					if(array[i][j] >= 3){
						fprintf(fp,"%d", 4);
					}
					else{
						fprintf(fp,"%d", array[i][j] + 1);
					}
				}
				fprintf(fp, "\n");
			}
		}
		if(checker == 4){
			//too bad
		}
	}
		
	else{
		return 0;
	}
	fclose(fp);
	printf("\nImage saved.\n\n");
	return 0;
}
//DIM IMAGE

int dim(int *row, int *col, int array[*row][*col]){
	for(int i = 0; i < *row;i++){
		for(int j = 0; j < *col; j++){
			if(array[i][j] <= 0){
				printf(" ");;
			}
			if(array[i][j] == 1){
				printf(" ");
			}
			if(array[i][j] == 2){
				printf(".");
			}
			if(array[i][j] == 3){
				printf("o");
			}
			if(array[i][j] == 4){
				printf("O");
			}
			
		}
		printf("\n");
	}
}

//BRIGHTEN IMAGE

int brighten(int *row, int *col, int array[*row][*col]){
	for(int i = 0; i < *row;i++){
		for(int j = 0; j < *col; j++){
			if(array[i][j] >= 4){
				printf("0");;
			}
			if(array[i][j] == 0){
				printf(".");
			}
			if(array[i][j] == 1){
				printf("o");
			}
			if(array[i][j] == 2){
				printf("O");
			}
			if(array[i][j] == 3){
				printf("0");
			}

		}
		printf("\n");
	}
}
