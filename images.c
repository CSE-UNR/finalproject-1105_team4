// Authors: Alex Cornell and Brayton Arthur
//Date: 05/03/24
//Purpose: Final Project

// For an image file, end each line with the number 5 and conclude with one row dedicated to the number 6. Due to mysterious circumstances, either the load function or display function fill the array with an input of 0, and despite the presence of a printf("\n"); line between the column and row print loops, there are no line breaks being printed. 

#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 500


int width;
int height;
int pixels[MAX_SIZE][MAX_SIZE];

void displayMenu();
void loadImage();
void displayImage();
void editImage();
void cropImage();
void dimImage();
void brightenImage();
void saveImage();

int main(){
	int choice;
	do{
		displayMenu();
		printf("\nChoose from one of the options above: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				loadImage();
				break;
			case 2:
				displayImage();
				break; 
			case 3:
				editImage();
				break; 
			case 4:
				saveImage();
				break;
			case 0:
				printf("Goodbye!\n");
				break;
			default:
				printf("Invalid.\n");
				break;
		}
	}while(choice != 0);
	
	return 0;
}

void displayMenu() {
	printf("\n**ERINSTAGRAM**\n");
	printf("1. Load image\n");
	printf("2. Display image\n");
	printf("3. Edit image\n");
	printf("4. Save image\n");
	printf("0. Exit\n");
}

void loadImage(){
	char filename[100];
	printf("What is the name of the image file? ");
	scanf("%s", filename);

	FILE *file = fopen(filename, "r");
	
	for(height = 0; height < MAX_SIZE; height++){
		for(width = 0; width < MAX_SIZE; width++){
			if(pixels[width][height] == 5){
				height = 0;
				width++;
			}
			if(pixels[width][height] == 6){
				height = MAX_SIZE;
				width = MAX_SIZE;
			}
			fscanf(file, "%1d", &pixels[width][height]);
			
			
		}
	}

	
	
	if (file == NULL) { 
		printf("Could not find an image with that filename.");
		return;
	}
	fclose(file);
	printf("Image loaded successfully!\n");
}

void displayImage(){ // A
	printf("\nImage:\n\n");
	for(height = 0; height < MAX_SIZE; height++){ // B
		for(width = 0; width < MAX_SIZE; width++){ // C
			//printf("%d", pixels[width][height]);
			while(pixels[width][height] / pixels[width][height] == 1){ // D
				switch(pixels[width][height]){ // E
					case 0:
						printf(" ");
						break;
					case 1:
						printf(".");
						break;
					case 2:
						printf("o");
						break; 
					case 3:
						printf("O");
						break; 
					case 4:
						printf("0");
						break; 	
					case 5:
						printf("\n");
						break;	
					case 6:
						printf("\n");
						break;		
					default:
						printf("Invalid. Read integer: %d\n", pixels[width][height]);
						break;
			} // E
			break;
			} // D
		
		//break;
		
		}// C
	printf("\n");	
	break;
	} // B
} // A	
	
void editImage() {
	int editChoice;
	printf("\n**EDITING**\n");
	printf("1. Crop image\n");
	printf("2. Dim image\n");
	printf("3. Brighten image\n");
	printf("0. Back to main menu\n");
	printf("Enter your choice: ");
	scanf("%d", &editChoice);
	
	switch(editChoice){
		case 1:
			cropImage();
			break;
		case 2:	
			dimImage();
			break;
		case 3:	
			brightenImage();
			break;
		case 0:	
			printf("Returning to main menu...\n");
			break;
		default:	
			printf("Invalid.\n");
			break;
	}
}

void cropImage(){
	int topLeftX;
	int topLeftY;
	int botRightX;
	int botRightY;
	printf("Enter the position of the top left corner (x,y): ");
	scanf("%d,%d", &topLeftX, &topLeftY);
	printf("Enter the position of the bottom right corner (x,y): ");
	scanf("%d,%d", &botRightX, &botRightY);
	printf("\nImage:\n\n");
	for(height = topLeftY; height < botRightY; height++){ // B
		for(width = topLeftX; width < botRightX; width++){ // C
			//printf("%d", pixels[width][height]);
			while(pixels[width][height] / pixels[width][height] == 1){ // D
				switch(pixels[width][height]){ // E
					case 0:
						printf(" ");
						break;
					case 1:
						printf(".");
						break;
					case 2:
						printf("o");
						break; 
					case 3:
						printf("O");
						break; 
					case 4:
						printf("0");
						break; 	
					case 5:
						printf("\n");
						break;	
					case 6:
						printf("\n");
						break;		
					default:
						printf("Invalid. Read integer: %d\n", pixels[width][height]);
						break;
			} // E
			break;
			} // D
		
		//break;
		
		}// C
	printf("\n");	
	break;
	} // B
}
	
void dimImage(){
	printf("\n\nImage: \n");
	for(height = 0; height < MAX_SIZE; height++){
		for(width = 0; width < MAX_SIZE; width++){
		while(pixels[width][height] / pixels[width][height] == 1){
			if(pixels[width][height] == 0){
				printf(" ");
				break;
			}
			if(pixels[width][height] == 1){
				printf(" ");
				pixels[width][height]--;
				break;
			}
			if(pixels[width][height] == 2){
				pixels[width][height]--;
				printf(".");
				break;
			}
			if(pixels[width][height] == 3){
				pixels[width][height]--;
				printf("o");
				break;
			}
			if(pixels[width][height] == 4){ 
				pixels[width][height]--;
				printf("O");
				break;
			}
			if(pixels[width][height] == 5){
				printf("\n");
				break;
			}
			if(pixels[width][height] == 6){
				printf("\n");
				break;
			}	
			else{
				printf("Else");
				break;
			}
		}
		}
		printf("\n");
		break;
		}
	printf("\n");	
	}

void brightenImage() {
	printf("\n\nImage: \n");
	for(height = 0; height < MAX_SIZE; height++){
		for(width = 0; width < MAX_SIZE; width++){
		while(pixels[width][height] / pixels[width][height] == 1){
			if(pixels[width][height] == 0){
				printf(".");
				pixels[width][height]++;
				break;
			}
			if(pixels[width][height] == 1){
				pixels[width][height]++;
				printf("o");
				break;
			}
			if(pixels[width][height] == 2){
				pixels[width][height]++;
				printf("O");
				break;
			}
			if(pixels[width][height] == 3){
				pixels[width][height]++;
				printf("0");
				break;
			}
			if(pixels[width][height] == 4){
				pixels[width][height]++;
				break;
			}
			if(pixels[width][height] == 5){
				printf("\n");
				break;
			}
			if(pixels[width][height] == 6){
				printf("\n");
				break;
			}	
			else{
				printf("Else");
				break;
			}
		}
		}
		printf("\n");
		break;
		}
	}
void saveImage(){
	char filename[100];
	printf("What is the name of the image file that you would like to save to? ");
	scanf("%s", filename);
	FILE *file = fopen(filename, "w");
	fprintf(file, "%d", pixels);
	fclose(file);
	printf("\nImage saved!\n");
}




