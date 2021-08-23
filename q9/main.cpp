#include <stdio.h>
#include <string>
#include <iostream>

/* Question 4 */

/*Make a program in C/C++ or Java language that calculates the length of a string informed by the user (do not use any pre-existing function or method for this, such as len(), count(), strlen() or lenght());*/

using namespace std;

static int get_len(string word);

int main(void){
    string word = "";
    while (word != "-1")
    {
        cout << "Type the string (Type -1 to exit): ";
        getline(cin,word);
        cout << "Size: " << get_len(word) << endl;
    }
    
    return 0;
}

static int get_len(string word){
    uint32_t counter = 0;
    for(counter; word[counter] != '\0'; counter++);
    return counter;
}

