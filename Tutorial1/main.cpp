#include <iostream>
#include <fstream> // for file handling
#include <vector>

// using namespace std; // allow to use all methods available in the standard namespace, BAD PRACTICE
//  alternatively use scope resolution operator i.e. std::cout

int first_example();
int second_example();
int third_example();
int fourth_example();
int fifth_example();
int sixth_example();

int main()
{
    // first_example();
    // second_example();
    // third_example();
    // fourth_example();
    fifth_example();
    // sixth_example();
    return 0;
}

int first_example()
{
    // Printing to console
    std::cout << "Please enter a number" << std::endl
              << ">> ";
    int input_integer;

    // Reading input from commandline/console
    std::cin >> input_integer;

    // Printing to console
    std::cout << "You entered: " << input_integer << std::endl;

    return 0;
}

int second_example()
{
    // Reading from file
    std::ifstream input_file; // automatically allows read from file

    // Opening file
    input_file.open("input.txt");

    // Read line by line
    std::string line;
    while (std::getline(input_file, line))
    {
        std::cout << line << std::endl;
    }

    /*
    // Read character by character
    char character;
    while (input_file.get(character))
    {
        std::cout << character << std::endl;
    }
    */

    input_file.close();

    return 0;
}

int third_example()
{
    // Writing to file
    std::ofstream output_file; // automatically allows write to file

    // Opening file
    output_file.open("output.txt");

    // Writing to file
    output_file << "Hello World! This was written with an output stream" << std::endl;

    output_file.close();

    return 0;
}

int fourth_example()
{
    // use fstream
    std::fstream file_stream;
    file_stream.open("input.txt", std::ios::in | std::ios::out); // allows read and write from/to the stream
    // not set automatically, must be set manually
    file_stream.close();
    return 0;
}

int fifth_example()
{
    // for loop
    // int arr[5]; // this is an array
    // this is a vector

    std::vector<int> items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(3);

    int length = items.size();

    for (int index_of_item = 0; index_of_item < length; ++index_of_item) // pre-increment less expensive than post-increment
    {
        std::cout << items[index_of_item] << std::endl;
    }

    return 0;
}

int sixth_example()
{
    int index = 10;
    while (index > 0)
    {
        std::cout << "Hello World!" << std::endl;
        index -= 1;
    }

    return 0;
}
