#include <stdio.h>
#include <string>
#include <iostream>
#include <assert.h>
#include <time.h>

/* Question 3 */

/*Write an Unit Test using C/C++ or Java for the function ConcatRemove(s,t,k)*/

using namespace std;

static bool ConcatRemove(string s, string t, uint16_t k);
static string doConcatRemove(string s, string t, uint16_t k);
static bool auto_test(string s, string t, uint16_t k, bool desired_result);
static bool practic_test(string s, string t, uint16_t k);
static void remove_char(string *t);
static string rand_string_generator(void);
static char rand_char_generator(void);
static uint16_t rand_int_generator(void);

int main(void){
    string s,t;
    int k;
    
    srand (time(NULL));
    
    assert(auto_test("blablablabla","blablabcde",8,true));
    assert(auto_test("Tab","Tab",7,true));
    assert(practic_test("blablablabla","blablabcde",8));
    assert(practic_test("Tab","Tab",7));

    for(uint16_t i=0; i<5000; i++){
        s = rand_string_generator();
        t = rand_string_generator();
        k = rand_int_generator();
        cout << "Testing S: " << s << " T: " << t << " K: " << k << endl;
        assert(practic_test(rand_string_generator(),rand_string_generator(),rand_int_generator()));
    }
    
    return 0;
}

static string rand_string_generator(void){
    int rand_num;
    string word;

    rand_num = rand() % 100 +1;

    for(uint16_t i=0; i<rand_num; i++){
        word+=rand_char_generator();
    }
    return word;
}

static char rand_char_generator(void){
    int rand_num;
    char rand_char;
    rand_num = rand() % 26;
    rand_char = 'a' + rand_num;
    return rand_char;
}

static uint16_t rand_int_generator(void){
    uint16_t rand_num;
    rand_num = rand() % 100 + 1;
    return rand_num;
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

static string doConcatRemove(string s, string t, uint16_t k){
    uint16_t remove_moves = 0;
    uint16_t concat_moves =0;
    uint16_t moves_counter = 0;
    string desired = t;

    if (s.compare(t) != 0){
        for(uint8_t i=0;i<s.length();i++){
            if(s[i] != t[i]) {remove_moves = s.length()-i; break;}
        }
    }
    
    concat_moves = t.length() - (s.length() - remove_moves);
    
    t=s;

    while((moves_counter<remove_moves) && (moves_counter<k)){
        remove_char(&t);
        moves_counter++;
    }

    while((moves_counter + concat_moves) < k){
        if(!t.empty()){
            concat_moves++;
        }
        remove_char(&t);
        moves_counter++;
    }

    static uint16_t begin_concat = 0;
    begin_concat = t.length();

    while(moves_counter <k){
        t+=desired.at(begin_concat);
        begin_concat++;
        moves_counter++;
    }
    return t;
}

static void remove_char(string *t){
    if(t->empty()){
        return;
    }
    else {
        t->erase(t->length()-1,1);
    }
}

static bool auto_test(string s,string t, uint16_t k, bool desired_result){
    return (desired_result == ConcatRemove(s,t,k));
}

static bool practic_test(string s,string t, uint16_t k){
    return ((t==doConcatRemove(s,t,k)) == ConcatRemove(s,t,k));
}
