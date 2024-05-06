// Authors: Alex Cornell and Brayton Arthur
//Date: 05/03/24
//Purpose: Final Project

#include <stdio.h>


#define MAX_SIZE 1000


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
		printf("Choose from one of the options above: ");
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
	printf("0. Exit\n");
}

void loadImage(){
	char filename[100];
	printf("What is the name of the image file? ");
	scanf("%s", filename);

	FILE *file = fopen(filename, "r");
	for(height = 0; height < MAX_SIZE; height++){
		for(width = 0; width < MAX_SIZE; width++){
			fscanf(file, "%d", &pixels[height][width]);
		}
	}

	
	
	if (file == NULL) { 
		printf("Could not find an image with that filename.");
		return;
	}
	fclose(file);
	printf("Image loaded successfully!\n");
}

void displayImage(){
	printf("\nImage:\n");
	for(height = 0; height < MAX_SIZE; height++){
		for(width = 0; width < MAX_SIZE; width++){
			if(pixels[height][width] == 0){
				printf(" ");
			}
			if(pixels[height][width] == 1){
				printf(".");
			}
			if(pixels[height][width] == 2){
				printf("o");
			}
			if(pixels[height][width] == 3){
				printf("O");
			}
			if(pixels[height][width] == 4){
				printf("0");
			}
			else{
				break;
			}
			/*switch(pixels[height][width]){
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
				default:
					break;
					
			}*/
		}
	}	
}	
	
void editImage() {
	int editChoice;
	printf("\n**EDITING**\n");
	printf("1. Crop image\n");
	printf("2. Dim image\n");
	printf("3. Brighten image\n");
	printf("4. Save image\n");
	printf("0. Back to main menu\n");
	printf("Enter your choice: ");
	scanf("%d", &editChoice);
	
	switch (editChoice) {
		case 1:
			cropImage();
			break;
		case 2:	
			dimImage();
			break;
		case 3:	
			brightenImage();
			break;
		case 4:	
			saveImage();
			break;
		case 0:	
			printf("Returning to main menu...\n");
			break;
		default:	
			printf("Invalid.\n");
			break;
	}
}

void cropImage() {
}
	
void dimImage() {
/*
	for(height = 0; height < MAX_SIZE; height++){
		for(width = 0; width < MAX_SIZE; width++){
			if(pixels[height][width] == "o"){
				pixels[height][width] = "O"
			
			}
		}
	}
*/	
}

void brightenImage() {
}

void saveImage() {
}
		
			
	
	
	
