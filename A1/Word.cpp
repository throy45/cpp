#include "Word.h"

Word::Word(const char pChArray[], int n) : frequency{1}, num_list{}
{
    pCharArray = new int[n];
    for (int k = 0; k < n; ++k)
    {
        pCharArray[k] = pChArray[k];
    }
};