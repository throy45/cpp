#include <cassert>
#include <algorithm>
#include "Dictionary.h"
#include "Word.h"

void print_word_list(const std::list<Word> &wordList)
{
    for (auto &word : wordList)
    {
        std::cout << word << std::endl;
    }
}

void test_sorting_by_word_text()
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
    print_word_list(words);

    // Verify that the list is sorted correctly
    assert(words.front().get_word_text() == "apple");
    assert(words.back().get_word_text() == "cherry");
}

void test_sorting_by_word_frequency()
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
    words.sort(is_less_frequent);

    std::cout << "\nSorted by frequency:\n";
    print_word_list(words);

    // Verify that the list is sorted correctly
    assert(words.front().get_frequency() == 1);
    assert(words.back().get_frequency() == 3);
}

void test_sorting_by_word_length()
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
    words.sort(is_shorter);

    std::cout << "\nSorted by length:\n";
    print_word_list(words);

    // Verify that the list is sorted correctly
    assert(words.front().length() == 5);
    assert(words.back().length() == 6);
}

void test_sorting_in_dictionary()
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
    test_sorting_by_word_text();
    test_sorting_by_word_frequency();
    test_sorting_by_word_length();
    test_sorting_in_dictionary();

    std::cout << "All sorting tests passed!" << std::endl;

    return 0;
}
