#include<iostream>
using namespace std;
#include<cstring>
#include<string>



void printWord(const char* word);
void initializeWord(const char *sozcuk,char *secretWord);
void makeMove(char guess, const char *word, char* secretWord);
void drawBoard(int count);

int main() {
    

    
    const char *secretWord = "hangman";
    char *answer = new char[strlen(secretWord) + 1];
    char guess;
    int count = 0;
    

    initializeWord(secretWord,answer);
    while(strcmp(secretWord,answer) != 0) {
        
        printWord(answer);
        drawBoard(count);
        cout << "harf tahmini: ";
        cin >> guess;
        bool dogruTahmin = false;
        for(int i = 0; i < strlen(secretWord); i++) {
            if(secretWord[i] == guess) {
                answer[i] = secretWord[i];
                dogruTahmin = true;
            }
        }

        if(!dogruTahmin) {
            count++;
        }
        if(count == 4) {
            printWord(answer);
            drawBoard(count);
            cout << "right answer: " ; printWord(secretWord);
            break;
        }

        else {
            if (strcmp(secretWord, answer) == 0) {
                printWord(answer);
                drawBoard(count);
                cout << "You win the game! " << endl;
                break;
            }
        }
        

        
    }






    return 0;
}


void initializeWord(const char *word,char *secretWord) {
    for(int i = 0; i < strlen(word); i++) {
        secretWord[i]= '_';
    }
}

void printWord(const char* word) {
    
    for(int i = 0; i < strlen(word); i++) {
        cout << word[i] <<" ";
    }

    cout << endl;
}


void drawBoard(int count) {
    if(count == 0) {
        
        cout << "|------                         " << endl;
        cout << "|                               " << endl;        
        cout << "|                               " << endl;
        cout << "|                               " << endl;
        cout << "|                               " << endl;
        cout << "|                               " << endl;
        cout << "|___________                    " << endl;
    }
    else if(count == 1) {
        
        cout << "|------                         " << endl;
        cout << "|     |                         " << endl;        
        cout << "|     O                         " << endl;
        cout << "|                               " << endl;
        cout << "|                               " << endl;
        cout << "|                               " << endl;
        cout << "|___________                    " << endl;
    }

    else if(count == 2) {
        
        cout << "|------                         " << endl;
        cout << "|     |                         " << endl;        
        cout << "|     O                         " << endl;
        cout << "|     |                         " << endl;
        cout << "|     |                         " << endl;
        cout << "|                               " << endl;
        cout << "|___________                    " << endl;
    }

    else if(count == 3) {
        
        cout << "|------                         " << endl;
        cout << "|     |                         " << endl;        
        cout << "|     O                         " << endl;
        cout << "|    /|\\                       " << endl;
        cout << "|     |                         " << endl;
        cout << "|                               " << endl;
        cout << "|___________                    " << endl;
    }



    else if(count == 4) {
        
        cout << "|------                         " << endl;
        cout << "|     |                         " << endl;        
        cout << "|     O                         " << endl;
        cout << "|    /|\\                       " << endl;
        cout << "|     |                         " << endl;
        cout << "|    / \\                       " << endl;
        cout << "|___________                    " << endl;
        cout << "You lose the game! " << endl;
        
    }
}