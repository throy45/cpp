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
    int start = line.find_first_not_of(theDelimiters);
    while (start != string::npos)
    {
        int end = line.find_first_of(theDelimiters, start + 1);
        if (end == string::npos)
        {
            end = line.length();
        }
        words.push_back(line.substr(start, end - start));
        start = line.find_first_not_of(theDelimiters, end + 1);
    }
    return words;
}

void Dictionary::push_back_into_bucket(const string &wordText, size_t &lineNumber)
{
    size_t bucketIndex = bucket_index(wordText);
    for (auto &word : wordListBuckets[bucketIndex])
    {
        if (word.get_word_text() == wordText)
        {
            word.increment_frequency();
            word.push_back_line_number(lineNumber);
            return;
        }
    }
    wordListBuckets[bucketIndex].push_back(Word(wordText, lineNumber));
}

void Dictionary::extract_and_push(const string &line, size_t &lineNumber)
{
    vector<string> words = extract_words_from_line(line);
    for (auto &word : words)
    {
        push_back_into_bucket(word, lineNumber);
    }
}

Dictionary::Dictionary(const string &input_text_file, const string &delimiters) : filename(input_text_file), theDelimiters(delimiters)
{
    std::ifstream input_file(filename);
    if (!input_file)
    {
        std::cerr << "Error: could not open file '" << filename << "'\n";
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
        return;
    }
    for (auto &lineNumber : line_number_set)
    {
        std::cout << lineNumber << ": " << input_lines[lineNumber - 1] << '\n';
    }
}

// option 2
void Dictionary::print_original_buckets(const set<char> &charSet) const
{
    if (charSet.empty())
    {
        for (auto &bucket : wordListBuckets)
        {
            for (auto &word : bucket)
            {
                std::cout << word << '\n';
            }
        }
        return;
    }
    for (auto &bucket : wordListBuckets)
    {
        if (charSet.find(bucket.front().get_word_text()[0]) != charSet.end())
        {
            for (auto &word : bucket)
            {
                std::cout << word << '\n';
            }
        }
    }
}

// option 3
// TODO: check implementation from here down
void Dictionary::print_buckets_sorted_on_word_text(const set<char> &charSet) const
{
    if (charSet.empty())
    {
        for (auto &bucket : wordListBuckets)
        {
            list<Word> sortedBucket(bucket);
            sortedBucket.sort();
            for (auto &word : sortedBucket)
            {
                std::cout << word << '\n';
            }
        }
        return;
    }
    for (auto &bucket : wordListBuckets)
    {
        if (charSet.find(bucket.front().get_text()[0]) != charSet.end())
        {
            list<Word> sortedBucket(bucket);
            sortedBucket.sort();
            for (auto &word : sortedBucket)
            {
                std::cout << word << '\n';
            }
        }
    }
}

void Dictionary::print_buckets_sorted_on_word_frequency(const set<char> &charSet) const
{
    for (auto &bucket : wordListBuckets)
    {
        if (charSet.find(bucket.front().get_text()[0]) != charSet.end())
        {
            list<Word> sortedBucket(bucket);
            sortedBucket.sort([](const Word &a, const Word &b)
                              { return a.get_frequency() > b.get_frequency(); });
            for (auto &word : sortedBucket)
            {
                std::cout << word << '\n';
            }
        }
    }
}

void Dictionary::print_buckets_sorted_on_word_length(const set<char> &charSet) const
{
    for (auto &bucket : wordListBuckets)
    {
        if (charSet.find(bucket.front().get_text()[0]) != charSet.end())
        {
            list<Word> sortedBucket(bucket);
            sortedBucket.sort([](const Word &a, const Word &b)
                              { return a.get_text().length() > b.get_text().length(); });
            for (auto &word : sortedBucket)
            {
                std::cout << word << '\n';
            }
        }
    }
}
