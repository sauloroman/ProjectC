/* SISTEMA DE APRENDIZAJE DE INGLÉS CON CUESTIONARIOS INTERACTIVOS */

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define RED "\x1b[31m"
#define SIZE_OPTION 50
#define NEON_PURPLE "\033[1;35m"
#define NEON_GREEN "\033[1;92m"
#define RESET "\033[1;37m"

#define WORDSQUANTITY 20
#define WORDLENGTH 200
#define QUANTITYPHRASES 15

char words[WORDSQUANTITY][WORDLENGTH];
int positionWordArray = 0;

char phrasesToKnow[QUANTITYPHRASES][WORDLENGTH] = {
	"What's up? - ¿Qué onda? / ¿Qué tal?",  
	"No worries! - ¡No te preocupes! / Todo bien.",  
	"Chill out! - Relájate / Tranquilízate.",  
	"I'm down. - Me apunto / Estoy dentro.",  
	"That’s lit! - ¡Eso está genial!",  
	"Hit me up. - Escríbeme / Llámame.",  
	"No cap. - No es broma / Es en serio.",  
	"Lowkey - En secreto / Sutilmente.",  
	"Highkey - Muy obvio / Abiertamente.",  
	"It sucks. - Es una porquería / Es una mierda.",  
	"Bummer! - ¡Qué mala onda! / ¡Qué lástima.",  
	"Go off! - Dale con todo / Exprésate sin miedo.",  
	"Deadass - Hablando en serio / De verdad.",  
	"Take an L - Perder / Fracasar.",  
	"Salty - Ardido / Enojado.",  
	"Vibe check - ¿Buena vibra o no?"
};

// Function declarations
void printHeader( int size, char message[]);
void welcomeScreen( void );

// Show Menus Functions
void showOptions( int numberOfOptions, char options[numberOfOptions][SIZE_OPTION]);
void showWordsAndPhrasesMenu( void );
void showMenu( void );

// Words and phrases functions
void wordsAndPhrasesScreen( void );
void createNewWord( int position, char words[WORDSQUANTITY][WORDLENGTH] );
void createNewPhrase( char phrases[] );
void showSavedWords( int position, char words[WORDSQUANTITY][WORDLENGTH] );
void showOnePhraseToKnow( int quantityPhrases, char phrases[quantityPhrases][WORDLENGTH] );

// Tests functions
void testsScreen( void );

// Validate inputs
int validateChosenMenuOption( int lowerBound, int upperBound );

int main ( void ) {
	
	setlocale(LC_ALL, "");
	srand(time(NULL));
	printf(RESET);
	
	int chosenOption, exit = 0;
	
	welcomeScreen();
	
	do {
		showMenu();
		chosenOption = validateChosenMenuOption(1, 4);
		
		switch( chosenOption ) {
			case 1:
				wordsAndPhrasesScreen();
				break;
			case 2:
				testsScreen();
				break;
			case 3:
				break;
			case 4:
				exit = 1; 
				break;
		}	
		
	} while ( exit != 1 );
	
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
	char options[4][SIZE_OPTION] = {
		"Create new word",
		"See all my words",
		"Phrases to know",
		"Return",
	};
	showOptions(4, options);
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
	
	int exit = 0;
	int chosenOption;
	
	do {
		printHeader(40, "WORDS AND PHRASES");
		showWordsAndPhrasesMenu();
		chosenOption = validateChosenMenuOption(1, 4);
		
		switch( chosenOption ) {
			case 1: 
				createNewWord( positionWordArray, words );
				positionWordArray++;
				break;
			case 2:
				showSavedWords( positionWordArray, words );
				break;
			case 3:
				showOnePhraseToKnow( QUANTITYPHRASES, phrasesToKnow );
				break;
			case 4:
				exit = 1;
				break;
		}
	} while( exit != 1 );

}

void createNewWord( int position, char words[WORDSQUANTITY][WORDLENGTH] ) {
	char word[WORDLENGTH];
	
	printf("Enter your new word: ");
	scanf("%s", word);
	
	if ( position == WORDSQUANTITY - 1 ) {
		printf("The dictionary words is already full\n");
		return;
	}
	
	printf("The word saved correctly\n\n");
	strcpy(words[position], word);
	system("cls");
}

void showSavedWords( int position, char words[WORDSQUANTITY][WORDLENGTH] ) {
	system("cls");
	printHeader(40, "YOUR SAVED WORDS");
	int i;
	for ( i = 0; i < position; i++ ) {
		printf(NEON_PURPLE "%d. %3s\n" RESET, i+1, words[i] );
	}	
	printf("\n");
}

void showOnePhraseToKnow( int quantityPhrases, char phrases[quantityPhrases][WORDLENGTH] ) {
	system("cls");
	printHeader(40, "HERE YOU GO A NEW PHRASE");
	int randomNum = rand() % quantityPhrases;
	printf("%d", randomNum);
	printf( RED "%5s\n\n" RESET, phrases[randomNum] );
}

void testsScreen( void ) {
	system("cls");
	
	int exit = 0;
	int chosenOption;
	printHeader(40, "TRY TESTS AND IMPROVE");
	gets("");
}
