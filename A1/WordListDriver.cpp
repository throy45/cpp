#include <iostream>
#include "WordList.h"

using std::cout;
using std::endl;

void testWordList()
{
    WordList bucket;
    Word t1("Hello", 1);
    bucket.addSorted(t1);
    Word t2("Hello", 11);
    bucket.addSorted(t2);
    Word t3("Hello", 111);
    bucket.addSorted(t3);
    Word tArray[]{Word("How", 1), Word("are", 11), Word("you", 2),
                  Word("today?", 22), Word("#tag", 3), Word("bye", 3)};
    for (Word t : tArray)
    {
        bucket.addSorted(t);
    }
    bucket.print(cout); // ideally we prefer cout << bucket << endl;
    cout << endl;
}