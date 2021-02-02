#include <cstring>
#include <iostream>
#include <string>
#define L 30

using namespace std;

/*void longerWord(char* sentence, char* outWord,int& length)         
{
    char* toCheck = new char [L];
    for (int i = 0; i < L; i++)
    {
        toCheck[i] = NULL;
    }
    
    int counter = 0;
    const char* tok = " ";

    outWord = strtok(sentence, tok);
    length = strlen (outWord);

    while(strtok(NULL, tok)!= NULL){
        toCheck = strtok(NULL, tok);
        counter = strlen(toCheck);
        if (counter >= length){
            outWord = toCheck;
            length = counter;
            counter = 0;
        }
    }
    
    delete [] toCheck;
}*/

void longerWord(char* sentence, char outWord[], int& length)
{
    char* toCheck = new char[L];     // inizializzo un array di char "temporaneo" per eseguire il confronto
    for (int i = 0; i < L; i++) {
        toCheck[i] = NULL;
    }
    int counter = 0;
    length = 0;
    char* pch = sentence;
    int i = 0;
    int k = 0;
    while (*(sentence + i) != '\0') {
        while (*(pch + k) != ' ') {    // copio la parola in toCheck
            toCheck[k] = *(pch + k);
            counter++;
            k++;
            i++;
        }

        pch += k + 1;
        i++;
        k = 0;

        if (counter >= length) {                 // se la parola è più lunga di quella salvata, la copio nella striga output
            length = counter;                    
            counter = 0;                        // riazzero counter
            for (int j = 0; j < length; j++) {
                outWord[j] = toCheck[j];
            }
            outWord[length] = '\0';             // termino la stringa out
        }
    }

    delete[] toCheck;
}

int main()
{
    string line;
    char word [L];
    int length = -1;

    // leggi frase da stdin in stringa
    getline(cin, line);

    // copia stringa da variabile di tipo string a variabile di tipo char*
    char* cstr = new char[line.length() + 1];
    strcpy(cstr, line.c_str());
    int strLength = strlen(cstr);
    *(cstr + strLength) = '\0';

    if (strlen(cstr) == 0) {
        cout << "errore";
    }

    longerWord(cstr, word, length);
    cout << word << " " << length;

    return 0;
}