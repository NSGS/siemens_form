#include <stdio.h>
#include <iostream>

/* Question 2 */

/*Write a C/C++ or Java program that prints each number from 1 to 100 on a new line.

For each multiple of 3, print "Foo" instead of the number.
For each multiple of 5, print "Baa" instead of the number.
For multiple numbers simultaneously of 3 and 5, print "FooBaa", instead of the number.

Your solution should be using as few lines of code as possible, but you should produce efficient code.*/

using namespace std;

static void printer(int number);

int main(void){
    for(uint8_t i=1;i<=100;i++){
        printer(i);
    }
    return 0;
}

static void printer(int number){
    if (number%15 == 0) cout << "FooBaa";
    else if (number%3 == 0 ) cout << "Foo";
    else if (number%5 == 0 ) cout << "Baa";
    else cout << number;
    cout << endl;
}