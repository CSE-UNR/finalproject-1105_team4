// Authors: Alex Cornell and Brayton Arthur
//Date: 05/03/24
//Purpose: Final Project

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
	int width;
	int height;
	int pixels[MAX_SIZE][MAX_SIZE];
} Image; 

void displayMenu();
void loadImage(Image *image);
void displayImage(const Image *image);
void editImage(Image *image);
void cropImage(Image *image);
void dimImage(Image *image);
void brightenImage(Image *image);
void saveImage(const Image *image);

int main() {
	Image image;
	bool exitProgram = false;
	
	while(!exitProgram) {
		displayMenu();
		int choice;
		printf("Choose from one of the options above: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				loadImage(&image);
				break;
			case 2:
				displayImage(&image);
				break; 
			case 3:
				editImage(&image);
				break; 
			case 0:
				exitProgram = true;
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

void loadImage(Image *image) {
	char filename[100];
	printf("What is the name of the image file? ");
	scanf("%s", filename);
	
	FILE *file = fopen(filename, "r");
	if (file == NULL) { 
		printf("Could not find an image with that filename.");
		return;
	}
	
	fscanf(file, "%d %d", &image->width, &image->height);
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			fscanf(file, "%d", &image->pixels[i][j]);
		}
	}
	
	fclose(file);
	printf("Image loaded successfully!\n");
}

void displayImage(const Image *image) {
	printf("\nImage:\n");
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			char ch = image->pixels[i][j] >= 128 ? '#' : '.';
			printf("%c", ch);
		}
		printf("\n");
	}
}

void editImage(Image *image) {
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
			cropImage(image);
			break;
		case 2:	
			dimImage(image);
			break;
		case 3:	
			brightenImage(image);
			break;
		case 4:	
			saveImage(image);
			break;
		case 0:	
			printf("Returning to main menu...\n");
			break;
		default:	
			printf("Invalid.\n");
			break;
	}
}

void cropImage(Image *image) {
}

void dimImage(Image *image) {
}

void brightenImage(Image *image) {
}

void saveImage(const Image *image) {
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
