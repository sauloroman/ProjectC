#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define RED "\x1b[31m"
#define SIZE_OPTION 50
#define NEON_PURPLE "\033[1;35m"
#define NEON_GREEN "\033[1;92m"
#define RESET "\033[1;37m"
#define NEON_BLUE "\033[38;2;31;81;255m"

#define WORDSQUANTITY 20
#define WORDLENGTH 200
#define QUANTITYPHRASES 15
#define QUANTITYQUESTIONSPHRASES 5
#define QUANTITYQUESTIONOPTIONS 4
#define QUANTITYOFTESTS 100
#define QUANTITYOFLECTURES 3
#define LECTURELENGTH 1000
#define QUANTITYLECTURES 3
#define QUANTITYCOMMENTS 10
#define COMMENTLENGTH 200

char words[WORDSQUANTITY][WORDLENGTH];
char wordsInSpanish[WORDSQUANTITY][WORDLENGTH];
char comments[QUANTITYCOMMENTS][COMMENTLENGTH];
int testsResults[QUANTITYOFTESTS];

int quantityOfWordsSaved = 0;
int quantityOfTestsWords = 0;
int quantityOfTestsPhrases = 0;
int wordsCorrectCounter = 0, wordIncorrectCounter = 0;
int quantityComments = 0, quantityNoComments = 0;
int counterRightQuestions = 0, counterIncorrectQuestions = 0;
int counterLectureBeginner = 0, counterLectureIntermediate = 0, counterLectureAdvanced = 0;

char phrasesToKnow[QUANTITYPHRASES][WORDLENGTH] = {
	"What's up?",  
	"No worries!",  
	"Chill out!",  
	"I'm down.",  
	"That’s lit!",  
	"Hit me up.",  
	"No cap.",  
	"Lowkey.",  
	"Highkey.",  
	"It sucks.",  
	"Bummer!",  
	"Go off!",  
	"Deadass",  
	"Take an L",  
	"Salty",  
	"Vibe check"
};

char phrasesToKnowInSpanish[QUANTITYPHRASES][WORDLENGTH] = {
    "¿Qué onda? / ¿Qué tal?",
    "¡No te preocupes! / Todo bien.",
    "Relájate / Tranquilízate",
    "Me apunto / Estoy dentro.",
    "¡Eso está genial!",
    "Escríbeme / Llámame.",
    "No es broma / Es en serio.",
    "En secreto / Sutilmente.",
    "Muy obvio / Abiertamente.",
    "Es una porquería / Apesta.",
    "¡Qué mala onda! / ¡Qué lástima!",
    "Dale con todo / Exprésate sin miedo.",
    "Hablando en serio / De verdad.",
    "Perder / Fracasar.",
    "Ardido / Enojado.",
    "¿Buena vibra o no?"
};

char lectures[QUANTITYLECTURES][3][LECTURELENGTH] = {
	{
		"A Day at the Park",
		"Tom loves going to the park. Every Saturday, he wakes up early and eats breakfast. Then, he takes his dog, Max, and walks to the park. Max loves to run and play with other dogs. Tom likes to sit on a bench and read a book. Sometimes, he brings a sandwich and eats lunch there. The park is beautiful, with many trees and flowers.",
		"Birds sing in the trees, and children play on the swings. Tom enjoys the fresh air and the warm sunshine. After a few hours, he and Max start walking home. On the way, they stop at a small shop to buy some ice cream. When they arrive home, they feel happy and relaxed, ready for another great weekend."
	},
	{
		"The Mysterious Letter",
		"Sarah found an old letter in her grandmother’s attic. The paper was yellow, and the ink was faded. She carefully opened it and started reading. 'Dear Alice,' it began, 'I have hidden the treasure where the old oak tree stands.' Sarah’s heart started beating fast. Was this a real treasure map? She remembered a huge oak tree in the garden.",
		"Excited, she ran outside and started digging near its roots. The sun was setting, and the air was cool. After a few minutes, her shovel hit something hard. She dug faster and finally uncovered a small wooden box. With shaking hands, she opened it… and inside, she found old photographs and a golden locket. It wasn’t gold coins, but it was still a treasure—her family’s lost memories. She smiled, realizing that sometimes, the most valuable things aren’t gold or money, but the stories and love we share."
	},
	{
		"The Time Traveler’s Dilemma",
		"Dr. James Carter had spent years working on his time machine. Finally, on a cold December night, he activated it. The machine whirred, and in seconds, he found himself in the year 1850. He looked around in amazement—horse-drawn carriages, gas lamps, and people dressed in old-fashioned clothes. But something was wrong. His machine was gone! He panicked. Without it, he was stuck in the past forever.",
		"James took a deep breath and tried to think. He needed tools, but modern technology didn’t exist yet. He walked through the town, observing blacksmiths, carpenters, and engineers. Perhaps he could use their skills to rebuild the machine. But how would he explain his knowledge? Would they believe him? As he sat in a quiet alley, he realized that history was watching him. If he made one mistake, he could change the future forever."
	}	
};

// Function declarations
void printHeader( int size, char message[]);
void welcomeScreen( void );

// Show Menus Functions
void showOptions( int numberOfOptions, char options[numberOfOptions][SIZE_OPTION]);
void showWordsAndPhrasesMenu( void );
void showTestsMenu(void);
void showMenu( void );

// Words and phrases functions
void wordsAndPhrasesScreen( void );
void createNewPhrase( char phrases[] );
void createNewWord( 
	int quantityOfWordsSaved, 
	char words[WORDSQUANTITY][WORDLENGTH], 
	char wordsInSpanish[WORDSQUANTITY][WORDLENGTH] 
);
void showSavedWords( 
	int quantityOfWordsSaved, 
	char words[WORDSQUANTITY][WORDLENGTH], 
	char wordsInSpanish[WORDSQUANTITY][WORDLENGTH] 
);
void showOnePhraseToKnow( 
	int quantityPhrases, 
	char phrases[QUANTITYPHRASES][WORDLENGTH],  
	char phrasesInSpanish[QUANTITYPHRASES][WORDLENGTH] 
);

// Tests functions
void testsScreen( void );
void studyWords( 
	int quantityOfWordsSaved, 
	char words[WORDSQUANTITY][WORDLENGTH], 
	char wordsInSpanish[WORDSQUANTITY][WORDLENGTH] 
);
void studyPhrases (
	char phrases[QUANTITYPHRASES][WORDLENGTH],  
	char phrasesInSpanish[QUANTITYPHRASES][WORDLENGTH] 
);
void readingActivities( char lectures[QUANTITYLECTURES][3][LECTURELENGTH] );
void showLecture( char text[3][LECTURELENGTH] );
void askForComment( char comments[QUANTITYCOMMENTS][COMMENTLENGTH] );
void incrementCounterLectures( int level );

// Stadistics Functions
void stadisticsScreen( void );
void printSeparator( int columnsWidths[], int numColumns );
void printRow( char *row[], int columnsWidths[], int numColumns );
void counterWordStadistics( void );
void counterPhrasesStadistics( void );
void counterReadingStadistics( void );

// Helper functions
int validateChosenMenuOption( int lowerBound, int upperBound );
int isValueInArray( int value, int size, int arr[] );
int isWordInArray( char word[], int size, char words[QUANTITYQUESTIONOPTIONS][WORDLENGTH] );
int recursiveSum( int arr[], int n );
float recursiveAverage( int arr[], int n );

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
				stadisticsScreen();
				break;
			case 4:
				exit = 1; 
				break;
		}	
		
	} while ( exit != 1 );
	
	
	return 0;
}

int recursiveSum( int arr[], int n ) {
	if ( n == 0 ) return 0;
	return arr[ n - 1 ] + recursiveSum( arr, n - 1 ); // Recursive calls
}

float recursiveAverage( int arr[], int n ) {
	if ( n == 0 ) return 0;
	int sum = recursiveSum( arr, n );
	return (float) sum / n;
}

void printSeparator( int columnsWidths[], int numColumns ) { 
	printf(NEON_BLUE);
	int i;
	for ( i = 0; i < numColumns; i++ ) {
		printf("+");
		int j;
		for( j = 0; j < columnsWidths[i]; j++ ) {
			printf("-");
		}
	}
	
	printf("+\n" RESET);
}

void printRow( char *row[], int columnsWidths[], int numColumns ) {
	int i;
	for ( i = 0; i < numColumns; i++ ) {
		printf("| %-*s", columnsWidths[i] - 1, row[i] );
	}
	printf("|\n");
}

void counterWordStadistics( void ){
	int numColumns = 3;
	int columnsWidths[] = {5, 25, 15};
	char *headers[]= {"No.", "Word Concept", "Quantity"};
	printSeparator(columnsWidths, numColumns);
	printRow( headers, columnsWidths, numColumns );
	printSeparator(columnsWidths, numColumns);
	
	char quantityOfWordsSavedStr[2];
	sprintf( quantityOfWordsSavedStr, "%d", quantityOfWordsSaved );
	char quantityOfTestsWordsStr[2];
	sprintf( quantityOfTestsWordsStr, "%d", quantityOfTestsWords );
	char wordsCorrectCounterStr[2];
	sprintf(wordsCorrectCounterStr, "%d", wordsCorrectCounter );
	char wordIncorrectCounterStr[2];
	sprintf(wordIncorrectCounterStr, "%d", wordIncorrectCounter );
	
	float average = 0;
	int sum = 0;
	int values[4] = { quantityOfWordsSaved, quantityOfTestsWords, wordsCorrectCounter, wordIncorrectCounter }; 
	
	sum = recursiveSum(values, 4);
	char sumStr[2];
	sprintf(sumStr, "%d", sum );
	
	average = recursiveAverage(values, 4);
	char averageStr[2];
	sprintf(averageStr, "%.2f", average );
	
	char *data[][3] = {
		{"01", "Created Words",  quantityOfWordsSavedStr},
		{"02", "Tests-Words Taken",  quantityOfTestsWordsStr},
		{"03", "Tests-Words Correct ",  wordsCorrectCounterStr},
		{"04", "Tests-Words Incorrect",  wordIncorrectCounterStr},
		{"--", "Sum", sumStr},
		{"--", "Average",  averageStr},
	};
	int numRows = sizeof( data ) / sizeof (data[0]);
	int i;
	for( i = 0; i < numRows; i++ ) {
		printRow( data[i], columnsWidths, numColumns );
	}
	printSeparator(columnsWidths, numColumns);
	printf("\n");
}

void counterPhrasesStadistics( void ) {
	int numColumns = 3;
	int columnsWidths[] = {5, 25, 15};
	char *headers[]= {"No.", "Phrase Concept", "Quantity"};
	printSeparator(columnsWidths, numColumns);
	printRow( headers, columnsWidths, numColumns );
	printSeparator(columnsWidths, numColumns);
	
	char quantityOfTestsPhrasesStr[2];
	sprintf( quantityOfTestsPhrasesStr, "%d", quantityOfTestsPhrases );
	char counterRightQuestionsStr[2];
	sprintf(counterRightQuestionsStr, "%d", counterRightQuestions );
	char counterIncorrectQuestionsStr[2];
	sprintf(counterIncorrectQuestionsStr, "%d", counterIncorrectQuestions );
	
	float average = 0;
	int sum = 0;
	int values[3] = { quantityOfTestsPhrases, counterRightQuestions, counterIncorrectQuestions }; 
	
	sum = recursiveSum(values, 3);
	char sumStr[2];
	sprintf(sumStr, "%d", sum );
	
	average = recursiveAverage(values, 3);
	char averageStr[2];
	sprintf(averageStr, "%.2f", average );
	
	char *data[][3] = {
		{"01", "Tests-Phrases Taken",  quantityOfTestsPhrasesStr},
		{"02", "Tests-Phrases Correct",  counterRightQuestionsStr},
		{"03", "Tests-Phrases Incorrect",  counterIncorrectQuestionsStr},
		{"--", "Sum", sumStr},
		{"--", "Average",  averageStr},
	};
	int numRows = sizeof( data ) / sizeof (data[0]);
	int i;
	for( i = 0; i < numRows; i++ ) {
		printRow( data[i], columnsWidths, numColumns );
	}
	printSeparator(columnsWidths, numColumns);
	printf("\n");
}

void counterReadingStadistics( void ) {
	int numColumns = 3;
	int columnsWidths[] = {5, 25, 15};
	char *headers[]= {"No.", "Reading Concept", "Quantity"};
	printSeparator(columnsWidths, numColumns);
	printRow( headers, columnsWidths, numColumns );
	printSeparator(columnsWidths, numColumns);
	
	char quantityCommentsStr[2];
	sprintf(quantityCommentsStr, "%d", quantityComments );
	char quantityNoCommentsStr[2];
	sprintf(quantityNoCommentsStr, "%d", quantityNoComments );
	char counterLectureBeginnerStr[2];
	sprintf(counterLectureBeginnerStr, "%d", counterLectureBeginner );
	char counterLectureIntermediateStr[2];
	sprintf(counterLectureIntermediateStr, "%d", counterLectureIntermediate );
	char counterLectureAdvancedStr[2];
	sprintf(counterLectureAdvancedStr, "%d", counterLectureAdvanced );
	
	float average = 0;
	int sum = 0;
	int values[5] = { quantityComments, quantityNoComments, counterLectureBeginner, counterLectureIntermediate, counterLectureAdvanced }; 
	
	sum = recursiveSum(values, 5);
	char sumStr[2];
	sprintf(sumStr, "%d", sum );
	
	average = recursiveAverage(values, 5);
	char averageStr[2];
	sprintf(averageStr, "%.2f", average );
	
	char *data[][3] = {
		{"01", "Reading Comments",  quantityCommentsStr},
		{"02", "Reading No Comments",  quantityNoCommentsStr},
		{"03", "Reading Beginner",  counterLectureBeginnerStr},
		{"04", "Reading Intermediate",  counterLectureIntermediateStr},
		{"05", "Reading Advanced",  counterLectureAdvancedStr},
		{"--", "Sum", sumStr},
		{"--", "Average",  averageStr},
	};
	int numRows = sizeof( data ) / sizeof (data[0]);
	int i;
	for( i = 0; i < numRows; i++ ) {
		printRow( data[i], columnsWidths, numColumns );
	}
	printSeparator(columnsWidths, numColumns);
	printf("\n");
}

void stadisticsScreen() {
	system("cls");
	while (getchar() != '\n'); 
	printHeader(40, "STADISTICS ABOUT YOUR PROGRESS");
	
	counterWordStadistics();
	counterPhrasesStadistics();
	counterReadingStadistics();
	
	printf("\nPress enter to return\n\n");
	getchar();
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
		"Tests Activities",
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

void showTestsMenu(void) {
	char options[4][SIZE_OPTION] = {
		"Study words",
		"Study phrases",
		"Reading activities",
		"Return"
	};
	showOptions(4, options);
}

void showReadingMenu(void) {
	char options[3][SIZE_OPTION] = {
		"Beginner Level",
		"Intermediate Level",
		"Advanced Level",
	};
	showOptions(3, options);
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
				createNewWord( quantityOfWordsSaved, words, wordsInSpanish);
				quantityOfWordsSaved++;
				break;
			case 2:
				showSavedWords( quantityOfWordsSaved, words, wordsInSpanish);
				break;
			case 3:
				showOnePhraseToKnow( QUANTITYPHRASES, phrasesToKnow, phrasesToKnowInSpanish );
				break;
			case 4:
				exit = 1;
				break;
		}
	} while( exit != 1 );

}

void createNewWord( int quantityOfWordsSaved, char words[WORDSQUANTITY][WORDLENGTH], char wordsInSpanish[WORDSQUANTITY][WORDLENGTH]) {
	char word[WORDLENGTH];
	char wordInSpanish[WORDLENGTH];
	
	printf("Enter your new word: ");
	scanf("%s", word);
	
	printf("Enter the meaning of the word: ");
	scanf("%s", wordInSpanish);
	
	if ( quantityOfWordsSaved == WORDSQUANTITY - 1 ) {
		printf("The dictionary words is already full\n");
		return;
	}
	
	printf("The word saved correctly\n\n");
	
	strcpy(words[quantityOfWordsSaved], word);
	strcpy(wordsInSpanish[quantityOfWordsSaved], wordInSpanish);
	
	system("cls");
}

void showSavedWords( int quantityOfWordsSaved, char words[WORDSQUANTITY][WORDLENGTH], char wordsInSpanish[WORDSQUANTITY][WORDLENGTH]) {
	system("cls");
	printHeader(40, "YOUR SAVED WORDS");
	
	if( quantityOfWordsSaved == 0 ) {
		printf(RED "You have not created words yet\n\n" RESET );
		return;
	}
	
	int i;
	for ( i = 0; i < quantityOfWordsSaved; i++ ) {
		printf(NEON_PURPLE "%d. %3s -------- " RESET, i+1, words[i] );
		printf(NEON_BLUE "%3s\n" RESET, wordsInSpanish[i] );
	}	
	printf("\n");
}

void showOnePhraseToKnow( int quantityPhrases, char phrases[quantityPhrases][WORDLENGTH],  char phrasesInSpanish[QUANTITYPHRASES][WORDLENGTH] ) {
	system("cls");
	printHeader(40, "HERE YOU GO A NEW PHRASE");
	int randomNum = rand() % quantityPhrases;
	
	printf( NEON_BLUE "%5s", phrases[randomNum] );
	printf(  "-------- %s\n\n" RESET, phrasesToKnowInSpanish[randomNum] );
}

void testsScreen( void ) {
	system("cls");
	
	int exit = 0;
	int chosenOption;
	
	do {	
		printHeader(40, "TRY TESTS AND IMPROVE");
		showTestsMenu();
		chosenOption = validateChosenMenuOption(1, 4);
		
		switch(chosenOption) {
			case 1:				
				studyWords( quantityOfWordsSaved, words, wordsInSpanish );
				break;
			case 2:
				studyPhrases( phrasesToKnow, phrasesToKnowInSpanish );
				break;
			case 3:
				readingActivities( lectures );
				break;
			case 4:
				exit = 1;
				break;
		}
	} while( exit != 1 );
	
}

void showLecture( char text[3][LECTURELENGTH] ) {
	printHeader(40, "");
	int i;
	for ( i = 0; i < 3; i++ ) {
		if ( i == 0 ) {
			printf(NEON_GREEN "%5s\n\n" RESET, text[i] );
		} else {
			printf("%5s\n\n", text[i] );
		}
	}
}

void askForComment( char comments[QUANTITYCOMMENTS][COMMENTLENGTH] ) {
	while (getchar() != '\n'); 
	char comment[COMMENTLENGTH];
	
	printf(NEON_BLUE "Write a comment about this lecture (-1 TO QUIT): " RESET );
	scanf("%[^\n]s", comment);
	
	strcpy(comments[quantityComments], comment);
	
	if ( strcmp(comment, "-1") == 0 || strcmp(comment, "") == 0 ) {
		quantityNoComments--;
		printf("\nKeep Practicing\n\n");
	} else {
		quantityComments++;
		printf(NEON_GREEN "\nYou won one point +1" RESET);
		printf(NEON_GREEN "\nTHANKS FOR YOUR COMMENT\n\n" RESET);	
	}
}

void incrementCounterLectures( int level ) {
	switch( level ) {
		case 0: counterLectureBeginner++; break;
		case 1: counterLectureIntermediate++; break;
		case 2: counterLectureAdvanced++; break;
	}
}

void readingActivities( char lectures[QUANTITYLECTURES][3][LECTURELENGTH] ) {
	system("cls");
	printHeader(40, "READ EVERYDAY");
	
	int chosenOption, index;
	showReadingMenu();
	chosenOption = validateChosenMenuOption(1, 3);
	index = chosenOption - 1;
	
	system("cls");
	showLecture( lectures[index] );
	incrementCounterLectures( index );
	askForComment( lectures );
}

void studyWords( int quantityOfWordsSaved, char words[WORDSQUANTITY][WORDLENGTH], char wordsInSpanish[WORDSQUANTITY][WORDLENGTH] ) {
	while (getchar() != '\n');   // Limpia caracteres previos en el buffer
	if( quantityOfWordsSaved == 0 ) {
		printf(RED "You need to create words to study\n\n" RESET );
		return;
	}

	char userInput[WORDLENGTH];
	
	do {
		int randomNumber = rand() % quantityOfWordsSaved;		
		printf("\nHow do you write in English " NEON_BLUE "%s?\n" RESET, wordsInSpanish[randomNumber]);
	
		printf("Enter your answer (-1 to finish): ");
		scanf(" %[^\n]s", userInput);	
		
		if ( strcmp(userInput, "-1") == 0  ) break;

		int wordsEqual = strcmp(userInput, words[randomNumber]);
		
		if( wordsEqual == 0) {
			printf(NEON_GREEN "\n\nCorrect. You won one point +1\n" RESET);
			wordsCorrectCounter++;
		} else {
			printf(RED "\n\nIncorrect! ? The correct answer is: %s\n" RESET, words[randomNumber]);
			wordIncorrectCounter--;
		}	
		
	} while( strcmp(userInput, "-1") != 0 );
	
	quantityOfTestsWords++;
	system("cls");
}

int isValueInArray( int value, int size, int arr[] ) {
	int i;
	for ( i = 0; i < size; i++ ) {
		if ( arr[i] == value ) return 1;
	}
	return 0;
}

int isWordInArray( char word[], int size, char words[QUANTITYQUESTIONOPTIONS][WORDLENGTH] ) {
	int i;
	for ( i = 0; i < size; i++ ) {
		if (strcmp(word, words[i]) == 0) return 1;
	}
	return 0;
}

void studyPhrases (char phrases[QUANTITYPHRASES][WORDLENGTH], char phrasesInSpanish[QUANTITYPHRASES][WORDLENGTH] ) {
	int i, randomNumberQuestion, randomPositionAnswer;
	int questions[QUANTITYQUESTIONSPHRASES] = {0, 0, 0, 0, 0};
	
	for ( i = 0; i < QUANTITYQUESTIONSPHRASES; i++ ) {		
		int userInput;
		char options[QUANTITYQUESTIONOPTIONS][WORDLENGTH] = {0, 0, 0, 0};
		
		do {
			randomNumberQuestion = rand() % QUANTITYPHRASES;		
		} while( isValueInArray(randomNumberQuestion, QUANTITYQUESTIONSPHRASES, questions) == 1);
	
		questions[i] = randomNumberQuestion;
		printf("\n%d. What is the meaning of: " NEON_BLUE "%s?\n\n" RESET, i + 1, phrases[randomNumberQuestion] );
		
		randomPositionAnswer = rand() % QUANTITYQUESTIONOPTIONS;
		strcpy(options[randomPositionAnswer], phrasesInSpanish[randomNumberQuestion]);	 
		
		int i;
		for ( i = 0; i < QUANTITYQUESTIONOPTIONS; i++ ) {
			if ( i != randomPositionAnswer ) {
				int randomOption;
				char randomPhrase[WORDLENGTH];
				
				do {
					randomOption = rand() % QUANTITYPHRASES;	
					strcpy(randomPhrase, phrasesInSpanish[randomOption]);	
				} while( 
					randomOption == randomNumberQuestion || 					
					isWordInArray( randomPhrase, QUANTITYQUESTIONOPTIONS, options ) == 1 
				);
				
				strcpy(options[i], phrasesInSpanish[randomOption]);
			}
			printf("%d. %s\n", i + 1, options[i]);
		}
	
		userInput = validateChosenMenuOption(1, QUANTITYQUESTIONOPTIONS);
			
		if ( randomPositionAnswer == userInput - 1 ) {
			printf(NEON_GREEN "\n\nCORRECT --- +1 POINT\n" RESET);
			counterRightQuestions++;
		} else {
			printf(RED "\n\nINCORRECT --- -1 POINT\n" RESET);
			counterIncorrectQuestions--;
		}
	}
	
	testsResults[quantityOfTestsPhrases] = counterRightQuestions;
	quantityOfTestsPhrases++;
	printf("\n");
}
