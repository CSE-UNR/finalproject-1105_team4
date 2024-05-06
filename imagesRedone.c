// Authors: Alex Cornell and Brayton Arthur
//Date: 05/03/24
//Purpose: Final Project

#include <stdio.h>
#include <stdbool.h>

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
	while(choice != 0){
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
	}
	
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
		printf("%c", pixels[height]);
	}
}	
	
	
	
	
	
	
