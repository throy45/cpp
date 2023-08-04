#include "assignment5.h"
#include <iostream>
#include <fstream>

WordsVector read_words_into_vector(const std::string& inFileName) {
    std::ifstream ifs(inFileName);
    if (!ifs.is_open()) {
        std::cout << "Could not open file " << inFileName << std::endl;
        throw std::runtime_error("Could not open file " + inFileName);
    }
    WordsVector words_vector;
    std::copy(
        std::istream_iterator<std::string>(ifs),
        std::istream_iterator<std::string>(),
        words_vector);
    return words_vector;
}

WordsMap map_and_count_words_using_lambda(const WordsVector& wvec) {
    WordsMap wmap;
    std::for_each(
        wvec.begin(),
        wvec.end(),
        [&wmap](std::string word) {++wmap[word];});
    return wmap;
}

WordsMap map_and_count_words_using_functor(const WordsVector& wvec) {
    struct WordCountFunctor {
        WordsMap wmap;
        void operator()(std::string word) { ++wmap[word]; }
        WordsMap& getmap() { return wmap; }
    };
    WordCountFunctor wcf{};
    std::for_each(
        wvec.begin(),
        wvec.end(),
        wcf);
    return wcf.getmap();
}

WordsVector remove_duplicates(const WordsVector& words_vector) {
    WordsVector words_vec{ words_vector };

    std::sort(words_vec.begin(), words_vec.end());

    auto end = std::unique(words_vec.begin(), words_vec.end());

    words_vec.erase(end, words_vec.end());

    return words_vec;
}

bool is_palindrome(const std::string& phrase) {
    std::string temp;
    std::copy_if

        std::remove_copy_if(
            std::istream_iterator()
        )
}