#include <cassert>
#include <algorithm>
#include "Dictionary.h"
#include "Word.h"

void printWordList(const std::list<Word> &wordList)
{
    for (auto &word : wordList)
    {
        std::cout << word << std::endl;
    }
}

void testSortingByWordText()
{
    // Create a list of Word objects with different word texts
    Word cherry("cherry", 3);
    cherry.increment_frequency();
    cherry.increment_frequency();
    Word apple("apple", 1);
    Word banana("banana", 2);
    banana.increment_frequency();
    std::list<Word> words = {cherry, apple, banana};

    // Sort the list based on word text
    words.sort();

    std::cout << "\nSorted:\n";
    printWordList(words);

    // Verify that the list is sorted correctly
    assert(words.front().get_word_text() == "apple");
    assert(words.back().get_word_text() == "cherry");
}

void testSortingByWordFrequency()
{
    // Create a list of Word objects with different frequencies
    Word cherry("cherry", 3);
    cherry.increment_frequency();
    cherry.increment_frequency();
    Word apple("apple", 1);
    Word banana("banana", 2);
    banana.increment_frequency();
    std::list<Word> words = {cherry, apple, banana};

    // Sort the list based on word frequency
    words.sort(isLessFrequent);

    std::cout << "\nSorted by frequency:\n";
    printWordList(words);

    // Verify that the list is sorted correctly
    assert(words.front().get_frequency() == 1);
    assert(words.back().get_frequency() == 3);
}

void testSortingByWordLength()
{
    // Create a list of Word objects with different word lengths
    Word cherry("cherry", 3);
    cherry.increment_frequency();
    cherry.increment_frequency();
    Word apple("apple", 1);
    Word banana("banana", 2);
    banana.increment_frequency();
    std::list<Word> words = {cherry, apple, banana};

    // Sort the list based on word length
    words.sort(isShorter);

    std::cout << "\nSorted by length:\n";
    printWordList(words);

    // Verify that the list is sorted correctly
    assert(words.front().length() == 5);
    assert(words.back().length() == 6);
}

void testSortingInDictionary()
{
    // Create a Dictionary object
    Dictionary dictionary("input.txt");

    // Sort the buckets in the dictionary based on word text
    std::cout << "\nSorted by word text:\n";
    dictionary.print_buckets_sorted_on_word_text({'a', 'b', 'c'});

    // Sort the buckets in the dictionary based on word frequency
    std::cout << "\nSorted by frequency:\n";
    dictionary.print_buckets_sorted_on_word_frequency({'a', 'b', 'c'});

    // Sort the buckets in the dictionary based on word length
    std::cout << "\nSorted by length:\n";
    dictionary.print_buckets_sorted_on_word_length({'a', 'b', 'c'});
}

int mainT()
{
    testSortingByWordText();
    testSortingByWordFrequency();
    testSortingByWordLength();
    testSortingInDictionary();

    std::cout << "All sorting tests passed!" << std::endl;

    return 0;
}
