#include <stdio.h>
#include <string>
#include <iostream>

/* Question 3 */

/*Consider a string containing lowercase characters from the Portuguese alphabet. You can perform two types of operations on this string:
1. Concat a lowercase character from the Portuguese alphabet at the end of the string.
2. Remove the last character from the string. If the string is empty, it will remain empty.

Given an integer k and two strings s and t, determine if you can convert s to t using exactly k operations described above on s. If possible, the program prints 'yes', otherwise it prints 'no'.

For example, string s = [a, b, c] and string t = [d, e, f]. The number of moves k = 6. To convert s to t, we first remove all characters using 3 moves. Then we concatenate each of the characters of t in the order. In the sixth move, you will have the expected string s. If more movements are available than necessary, they can be eliminated by performing multiple removals on an empty string. If there are fewer movements, it would not be possible to create the new string.

Develop a C/C++ or Java language program that implements and uses the ConcatRemove (s, t, k) function. It should return the results 'yes' or 'no'.
The function has the following parameters:
s: starting string
t: desired string
k: an integer that represents the number of operations*/

using namespace std;

static bool ConcatRemove(string s, string t, uint16_t k);

int main(void){
    string s; 
    string t;
    uint16_t k = 0;
    while(1){
        cout << "Enter s: "; cin >> s;
        cout << "Enter t: "; cin >> t;
        cout << "Enter k: "; cin >> k;
        if(ConcatRemove(s,t,k)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
    return 0;
}

static bool ConcatRemove(string s, string t, uint16_t k){
    uint16_t remove_moves = 0;
    uint16_t concat_moves = 0;
    uint16_t min_moves = 0;

    if (s.compare(t) != 0){
        for(uint8_t i=0;i<s.length();i++){
            if(s[i] != t[i]) {remove_moves = s.length()-i; break;}
        }
    }

    concat_moves = t.length() - (s.length() - remove_moves);
    min_moves = concat_moves + remove_moves;

    if (k == min_moves ) return true;
    else if (k < min_moves) return false;
    else if (k >= s.length() + t.length()) return true;
    else if ((k - min_moves)%2 == 0) return true;
    else return false;
}
