#include "Dictionary.h"

/**
 * This function returns the bucket index of a given word in a dictionary based on its first letter.
 *
 * @param wordText A constant reference to a string object representing a word.
 * @return a size_t value, which represents the index of the bucket in which a given word should be
 * stored in the dictionary. The index is determined based on the first letter of the word, with
 * letters A-Z being mapped to indices 0-25 and non-letter characters being mapped to index 26.
 */
size_t Dictionary::bucket_index(const string &wordText) const
{
    size_t index = 26; // bucket index for words not beginning with a letter
    if (isalpha(wordText[0]))
    {
        if (isupper(wordText[0]))
            index = wordText[0] - 'A';
        else
            index = wordText[0] - 'a';
    }
    return index;
}

/**
 * This function extracts words from a given string by splitting it based on a set of delimiters and
 * returns a vector of the extracted words.
 *
 * @param line The input string from which words need to be extracted.
 * @return A vector of strings containing the words extracted from the input line, where each word is
 * separated by one or more delimiters.
 */
vector<string> Dictionary::extract_words_from_line(const string &line) const
{
    vector<string> words;
    size_t start = line.find_first_not_of(delimiters);
    while (start != string::npos)
    {
        size_t end = line.find_first_of(delimiters, start + 1);
        if (end == string::npos)
        {
            end = line.length();
        }
        words.push_back(line.substr(start, end - start));
        start = line.find_first_not_of(delimiters, end + 1);
    }
    return words;
}

/**
 * This function adds a new word to a dictionary and updates its frequency and line number if it
 * already exists in the dictionary.
 *
 * @param wordText A constant reference to a string representing the text of a word to be added to the
 * dictionary.
 * @param lineNumber lineNumber is a reference to a size_t variable that represents the line number
 * where the word appears in a text document. This parameter is used in the function to add the line
 * number to the Word object associated with the wordText if it already exists in the dictionary.
 * @return The function does not have a return type specified, so it does not return anything
 * explicitly. However, it does have a return statement inside an if statement that will cause the
 * function to exit early if a matching word is found and updated, so it will not execute the rest of
 * the loop or the push_back statement if that happens.
 */
void Dictionary::push_back_into_bucket(const string &wordText, size_t &lineNumber)
{
    size_t bucketIndex = bucket_index(wordText);
    for (auto &word : word_list_buckets[bucketIndex])
    {
        if (word.get_word_text() == wordText)
        {
            word.increment_frequency();
            word.push_back_line_number(lineNumber);
            return;
        }
    }
    word_list_buckets[bucketIndex].push_back(Word(wordText, lineNumber));
}

/**
 * The function extracts words from a given line and pushes them into a bucket along with the line
 * number.
 *
 * @param line A string representing a line of text from a document or file.
 * @param lineNumber A reference to a size_t variable that represents the line number of the current
 * line being processed in the dictionary. This variable is updated as new words are added to the
 * dictionary.
 */
void Dictionary::extract_and_push(const string &line, size_t &lineNumber)
{
    vector<string> words = extract_words_from_line(line);
    for (auto &word : words)
    {
        push_back_into_bucket(word, lineNumber);
    }
}

/**
 * This function reads a text file, extracts words using specified delimiters, and stores them in a
 * dictionary object.
 *
 * @param input_text_file The name or path of the input text file that contains the data to be read and
 * processed by the Dictionary constructor.
 * @param delimiters The "delimiters" parameter is a string that contains all the characters that will
 * be used to separate words in the input text file. These delimiters will be used to split each line
 * of the input file into individual words, which will then be added to the dictionary.
 */
Dictionary::Dictionary(const string &input_text_file, const string &delimiters) : file_name(input_text_file), delimiters(delimiters)
{
    std::ifstream input_file(file_name);
    if (!input_file)
    {
        std::cerr << "Error: could not open file '" << file_name << "'\n";
        exit(1);
    }
    string line;
    size_t lineNumber = 0;
    while (getline(input_file, line))
    {
        ++lineNumber;
        input_lines.push_back(line);
        extract_and_push(line, lineNumber);
    }
}

// option 1
/**
 * This function prints out lines from a dictionary object based on a set of line numbers.
 *
 * @param line_number_set A set of line numbers to be printed from the input_lines vector. If the set
 * is empty, all lines in the vector will be printed.
 */
void Dictionary::print_input_lines(const set<size_t> &line_number_set) const
{
    if (line_number_set.empty())
    {
        for (auto &line : input_lines)
        {
            std::cout << line << '\n';
        }
    }
    else
    {
        for (auto &lineNumber : line_number_set)
        {
            std::cout << lineNumber << ": " << input_lines[lineNumber - 1] << '\n';
        }
    }
}

// option 2
/**
 * This function prints the original buckets of a dictionary object, either for all letters or for a
 * specified set of letters.
 *
 * @param charSet A constant reference to a set of characters. It is used to determine which buckets of
 * words to print. If the set is empty, all buckets are printed. If the set contains specific
 * characters, only the buckets corresponding to those characters are printed. If the set contains the
 * character '!', the bucket for special characters is printed.
 */
void Dictionary::print_original_buckets(const set<char> &charSet) const
{
    if (charSet.empty())
    {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        size_t i = 0;
        for (auto &bucket : word_list_buckets)
        {
            std::cout << "<" << letters[i] << ">" << std::endl;
            ++i;
            for (auto &word : bucket)
            {
                std::cout << std::setw(15) << word << '\n';
            }
        }
    }
    else
    {
        for (auto &letter : charSet)
        {
            if (letter != '!')
            {
                std::cout << "<" << letter << ">" << std::endl;
                char c = static_cast<char>(toupper(letter));
                for (auto &word : word_list_buckets[c - 'A'])
                {
                    std::cout << std::setw(15) << word << '\n';
                }
            }
        }
        if (charSet.find('!') != charSet.end())
        {
            std::cout << "<>" << std::endl;
            for (auto &word : word_list_buckets[26])
            {
                std::cout << std::setw(15) << word << '\n';
            }
        }
    }
}

// option 3
/**
 * This function prints the contents of the dictionary's word list buckets sorted alphabetically by
 * word text, either for all letters or for a specified set of letters.
 *
 * @param charSet The parameter `charSet` is a constant reference to a set of characters. It is used to
 * filter the output of the function based on the first letter of the words in the dictionary. If
 * `charSet` is empty, the function will print all words in alphabetical order. If the set contains the
 * character '!', the bucket for special characters is printed.
 */
void Dictionary::print_buckets_sorted_on_word_text(const set<char> &charSet) const
{
    if (charSet.empty())
    {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        size_t i = 0;
        for (auto &bucket : word_list_buckets)
        {
            std::cout << "<" << letters[i] << ">" << std::endl;
            ++i;
            forward_list<Word> sorted_bucket;
            for (auto &word : bucket)
            {
                sorted_bucket.push_front(word);
            }
            sorted_bucket.sort();
            for (auto &word : sorted_bucket)
            {
                std::cout << std::setw(15) << word << std::endl;
            }
        }
    }
    else
    {
        for (auto &letter : charSet)
        {
            if (letter != '!')
            {
                std::cout << "<" << letter << ">" << std::endl;
                char c = static_cast<char>(toupper(letter));
                forward_list<Word> sorted_bucket;
                for (auto &word : word_list_buckets[c - 'A'])
                {
                    sorted_bucket.push_front(word);
                }
                sorted_bucket.sort();
                for (auto &word : sorted_bucket)
                {
                    std::cout << std::setw(15) << word << std::endl;
                }
            }
        }
        if (charSet.find('!') != charSet.end())
        {
            std::cout << "<>" << std::endl;
            forward_list<Word> sorted_bucket;
            for (auto &word : word_list_buckets[26])
            {
                sorted_bucket.push_front(word);
            }
            sorted_bucket.sort();
            for (auto &word : sorted_bucket)
            {
                std::cout << std::setw(15) << word << std::endl;
            }
        }
    }
}

// option 4
/**
 * This function prints the words in each bucket of a dictionary sorted by frequency, either for all
 * letters or for a specified set of letters.
 *
 * @param charSet The parameter `charSet` is a constant reference to a set of characters. It is used to
 * filter the output of the function to only include words that contain the characters in the set. If
 * the set is empty, the function will print all words in the dictionary. If the set contains the
 * character '!', the bucket for special characters is printed.
 */
void Dictionary::print_buckets_sorted_on_word_frequency(const set<char> &charSet) const
{
    if (charSet.empty())
    {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        size_t i = 0;
        for (auto &bucket : word_list_buckets)
        {
            std::cout << "<" << letters[i] << ">" << std::endl;
            ++i;
            forward_list<Word> sorted_bucket;
            for (auto &word : bucket)
            {
                sorted_bucket.push_front(word);
            }
            sorted_bucket.sort(is_less_frequent);
            for (auto &word : sorted_bucket)
            {
                std::cout << std::setw(15) << word << std::endl;
            }
        }
    }
    else
    {
        for (auto &letter : charSet)
        {
            if (letter != '!')
            {
                std::cout << "<" << letter << ">" << std::endl;
                char c = static_cast<char>(toupper(letter));
                forward_list<Word> sorted_bucket;
                for (auto &word : word_list_buckets[c - 'A'])
                {
                    sorted_bucket.push_front(word);
                }
                sorted_bucket.sort(is_less_frequent);
                for (auto &word : sorted_bucket)
                {
                    std::cout << std::setw(15) << word << std::endl;
                }
            }
        }
        if (charSet.find('!') != charSet.end())
        {
            std::cout << "<>" << std::endl;
            forward_list<Word> sorted_bucket;
            for (auto &word : word_list_buckets[26])
            {
                sorted_bucket.push_front(word);
            }
            sorted_bucket.sort(is_less_frequent);
            for (auto &word : sorted_bucket)
            {
                std::cout << std::setw(15) << word << std::endl;
            }
        }
    }
}

// option 5
/**
 * This function prints the words in the dictionary sorted by length, either for all letters or for a
 * specific set of letters.
 *
 * @param charSet A constant reference to a set of characters. It is used to filter the words that are
 * printed based on the characters present in the set. If the set is empty, all words are printed. If the set contains
 * the character '!', the bucket for special characters is printed.
 */
void Dictionary::print_buckets_sorted_on_word_length(const set<char> &charSet) const
{
    if (charSet.empty())
    {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        size_t i = 0;
        for (auto &bucket : word_list_buckets)
        {
            std::cout << "<" << letters[i] << ">" << std::endl;
            ++i;
            forward_list<Word> sorted_bucket;
            for (auto &word : bucket)
            {
                sorted_bucket.push_front(word);
            }
            sorted_bucket.sort(is_shorter);
            for (auto &word : sorted_bucket)
            {
                std::cout << std::setw(15) << word << std::endl;
            }
        }
    }
    else
    {
        for (auto &letter : charSet)
        {
            if (letter != '!')
            {
                std::cout << "<" << letter << ">" << std::endl;
                char c = static_cast<char>(toupper(letter));
                forward_list<Word> sorted_bucket;
                for (auto &word : word_list_buckets[c - 'A'])
                {
                    sorted_bucket.push_front(word);
                }
                sorted_bucket.sort(is_shorter);
                for (auto &word : sorted_bucket)
                {
                    std::cout << std::setw(15) << word << std::endl;
                }
            }
        }
        if (charSet.find('!') != charSet.end())
        {
            std::cout << "<>" << std::endl;
            forward_list<Word> sorted_bucket;
            for (auto &word : word_list_buckets[26])
            {
                sorted_bucket.push_front(word);
            }
            sorted_bucket.sort(is_shorter);
            for (auto &word : sorted_bucket)
            {
                std::cout << std::setw(15) << word << std::endl;
            }
        }
    }
}
