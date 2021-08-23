#include <stdio.h>
#include <iostream>

/* Question 10 */

/*Make a program in C/C++ or Java language that reverses a string informed by the user without using any temporary variable, buffer or any pre-existing function or method for this.*/

using namespace std;

static string reverse_string(string word);

int main(void){
    string word = "";
    while(word != "-1"){
        cout << "Type a string (Type -1 to exit): ";
        getline(cin,word);
        cout << reverse_string(word) << endl;
    }
    return 0;
}

static string reverse_string(string word){
    string reverse_string = "";
    for (int i=word.length()-1; i>=0;i--){
    reverse_string+=word[i];
    }
    return reverse_string;
}