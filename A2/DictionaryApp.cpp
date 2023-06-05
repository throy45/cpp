#include <iostream>
#include <sstream>
#include <string>
#include "Dictionary.h"

int mainMenu();
std::set<size_t> get_input_sizet_set();
std::set<char> get_input_char_set();
void option1(const Dictionary &dict);
void option2345(const Dictionary &dict, int choice);

int main()
{
    std::string filename;
    std::string delimiters;

    std::cout << "Enter the name of an input text file: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "File does not exist or cannot be opened" << std::endl;
        return 1;
    }
    file.close();

    std::cout << "Enter the seperator chracters: ";
    std::getline(std::cin, delimiters);

    if (delimiters.empty())
    {
        std::cout << "Separator characters cannot be empty. Please try again." << std::endl;
        return 1;
    }

    Dictionary dict{filename, delimiters};

    bool exitFlag = false;
    while (!exitFlag)
    {
        int choice = mainMenu();
        switch (choice)
        {
        case 0:
            std::cout << "Goodbye." << std::endl;
            exitFlag = true;
            break;
        case 1:
            option1(dict);
            break;
        default:
            option2345(dict, choice);
            break;
        }
    }
    return 0;
}

int mainMenu()
{
    int choice = -1;
    while (choice < 0 || choice > 5)
    {
        std::cout << "Choose of the following options: " << std::endl;
        std::cout << " 1 - Print the input lines" << std::endl;
        std::cout << " 2 - Print original unsorted tokens" << std::endl;
        std::cout << " 3 - Print tokens sorted by text" << std::endl;
        std::cout << " 4 - Print tokens sorted by frequency" << std::endl;
        std::cout << " 5 - Print tokens sorted by length" << std::endl;
        std::cout << " 0 - Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::string choiceStr;
        std::getline(std::cin, choiceStr);
        std::stringstream ss{choiceStr};
        ss >> choice;

        if (choice < 0 || choice > 5)
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return choice;
}

void print_source_file_and_delimiters(const std::string &filename, const std::string &delimiters)
{
    std::cout << "Dictionary source file: " << filename << std::endl;
    std::cout << "Separator characters: " << delimiters << std::endl;
}

void option1(const Dictionary &dict)
{
    std::cout << "Which lines? ";
    std::set<size_t> lines{get_input_sizet_set()};
    print_source_file_and_delimiters(dict.get_filename(), dict.get_delimiters());
    std::cout
        << "Input Lines" << std::endl
        << "===========" << std::endl;
    dict.print_input_lines(lines);
    std::cout << "===========" << std::endl
              << std::endl;
}

void option2345(const Dictionary &dict, int choice)
{
    std::cout << "Which buckets? ";
    std::set<char> buckets{get_input_char_set()};
    std::cout << std::endl;
    print_source_file_and_delimiters(dict.get_filename(), dict.get_delimiters());
    switch (choice)
    {
    case 2:
        std::cout << "Dictionary unsorted" << std::endl
                  << "===================" << std::endl;
        dict.print_original_buckets(buckets);
        std::cout << std::endl
                  << std::endl;
        break;
    case 3:
        std::cout << "Dictionary sorted by word text" << std::endl
                  << "==============================" << std::endl;
        dict.print_buckets_sorted_on_word_text(buckets);
        std::cout << std::endl
                  << std::endl;
        break;
    case 4:
        std::cout << "Dictionary sorted by word frequency" << std::endl
                  << "===================================" << std::endl;
        dict.print_buckets_sorted_on_word_frequency(buckets);
        std::cout << std::endl
                  << std::endl;
        break;
    case 5:
        std::cout << "Dictionary sorted by word length" << std::endl
                  << "================================" << std::endl;
        dict.print_buckets_sorted_on_word_length(buckets);
        std::cout << std::endl
                  << std::endl;
        break;
    }
}

bool isPositiveInteger(const std::string &s)
{
    if (s.empty())
    {
        return false;
    }
    for (auto c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

std::set<size_t> get_input_sizet_set()
{
    std::set<size_t> result;

    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss{input};

    std::string token;
    while (iss >> token)
    {
        if (isPositiveInteger(token))
        {
            result.insert(static_cast<size_t>(std::stoul(token)));
        }
    }
    return result;
}

std::set<char> get_input_char_set()
{
    std::set<char> result;

    std::string input;
    std::getline(std::cin, input);
    for (char c : input)
    {
        c = std::tolower(c);

        if (std::isalpha(c))
        {
            result.insert(c);
        }
    }
    return result;
}