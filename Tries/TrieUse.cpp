#include <iostream>
#include "Trie.h"
using namespace std;

int main(){
    Trie t;

    t.insertWord("are");
    t.insertWord("and");
    t.insertWord("be");
    t.insertWord("before");
    t.insertWord("the");
    t.insertWord("this");

    cout << "are is: " << t.search("are") << endl;
    cout << "and is: " << t.search("and") << endl;
    cout << "be is: " << t.search("be") << endl;
    cout << "before is: " << t.search("before") << endl;
    cout << "the is: " << t.search("the") << endl;
    cout << "this is: " << t.search("this") << endl;

    t.remove("and");
    t.remove("be");
    t.remove("this");
    cout << endl;

    cout << "are is: " << t.search("are") << endl;
    cout << "and is: " << t.search("and") << endl;
    cout << "be is: " << t.search("be") << endl;
    cout << "before is: " << t.search("before") << endl;
    cout << "the is: " << t.search("the") << endl;
    cout << "this is: " << t.search("this") << endl;

    return 0;
}