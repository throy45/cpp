#include "Dictionary.h"

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

void Dictionary::extract_and_push(const string &line, size_t &lineNumber)
{
    vector<string> words = extract_words_from_line(line);
    for (auto &word : words)
    {
        push_back_into_bucket(word, lineNumber);
    }
}

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
                char c = toupper(letter);
                for (auto &word : word_list_buckets[c - 'A'])
                {
                    std::cout << std::setw(15) << word << '\n';
                }
            }
        }
        if (charSet.contains('!'))
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
                char c = toupper(letter);
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
        if (charSet.contains('!'))
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
                char c = toupper(letter);
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
        if (charSet.contains('!'))
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
                char c = toupper(letter);
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
        if (charSet.contains('!'))
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
