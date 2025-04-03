/* SISTEMA DE APRENDIZAJE DE INGLÉS CON CUESTIONARIOS INTERACTIVOS */

#include<stdio.h>
#include <stdlib.h>

#define SIZE_OPTION 50
#define NEON_PURPLE "\033[1;35m"
#define NEON_GREEN "\033[1;92m"
#define RESET "\033[1;37m"

// Function declarations
void printHeader( int size, char message[]);
void wordsAndPhrasesScreen( void );
void welcomeScreen( void );

void showOptions( int numberOfOptions, char options[numberOfOptions][SIZE_OPTION]);
void showWordsAndPhrasesMenu( void );
void showMenu( void );

int validateChosenMenuOption( int lowerBound, int upperBound );

int main ( void ) {
	
	printf(RESET);
	
	int chosenOption;
	
	welcomeScreen();
	
	showMenu();
	chosenOption = validateChosenMenuOption(1, 4);
		
	switch( chosenOption ) {
		case 1:
			wordsAndPhrasesScreen();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: 
			break;
	}	
	
	return 0;
}

int validateChosenMenuOption( int lower, int upper ) {
	printf("\n");
	int option;
	
	do {
		printf("Choose an option: ");
		scanf("%d", &option);
		
		if ( option < lower || option > upper ) printf("Chosen option is not valid. Try again.\n\n");
	} while( option < lower || option > upper );
	
	return option;
}

void printHeader( int size, char message[] ) {
	int i;
	for ( i = size; i > 0; i-- ) printf("-"); 
	printf(NEON_GREEN "\n%s\n" RESET, message);
	for ( i = size; i > 0; i-- ) printf("-"); 
	printf("\n\n");
}

void showOptions( int numberOfOptions, char options[numberOfOptions][SIZE_OPTION]) {
	int i;
	for( i = 0; i < numberOfOptions; i++ ) {
		printf( NEON_PURPLE "[%d]. " RESET, i + 1);	
		printf( "%s\n", options[i] );
	}
}

void showMenu( void ) {
	system("cls");
	printHeader(30, "OPTIONS MENU");
	char options[4][SIZE_OPTION] = {
		"Words and Phrases",
		"Tests",
		"Stadistics",
		"Exit",
	};
	showOptions(4, options);
}

void showWordsAndPhrasesMenu( void ) {
	char options[5][SIZE_OPTION] = {
		"Create new word",
		"Create new phrase",
		"See all my words",
		"See all my phrases",
		"Return",
	};
	showOptions(5, options);
}

void welcomeScreen( void ) {	
	printHeader(40, "ENGLISH LANGUAGE LEARNING SYSTEM");
	
	char uta[6][50] = {
     	"  _      _                   _ ",
        " | |    (_)                 | |",
        " | |     _ _ __  _ __  _   _| |",
        " | |    | | '_ \\| '_ \\| | | |",
        " | |____| | | | | | | | |_| | |",
        " |______|_|_| |_|_| |_|\\__,_|_|",
    };
    
    int i;
    for (i = 0; i < 6; i++) {        
        printf(NEON_PURPLE "%s\n", uta[i]);
    }
    
	printf(RESET "\n\nPress Enter to continue...");
    getchar();
}

void wordsAndPhrasesScreen( void ) {
	
	system("cls");
	int chosenOption;
	
	printHeader(40, "WORDS AND PHRASES");
	showWordsAndPhrasesMenu();
	chosenOption = validateChosenMenuOption(1, 5);
	
}







