#include "WordList.h"

/**
 * This is the default constructor for the WordList class, which takes no arguments and has an empty body.
 */
WordList::WordList(){};

/**
 * This function creates a new WordList object by copying the contents of an existing WordList object.
 *
 * @param list The parameter "list" is a reference to an object of the class "WordList".
 * @return Nothing is being returned explicitly in this code snippet. However, if the constructor is
 * being called as part of an object creation, then the newly created object will be returned.
 */
WordList::WordList(const WordList &list)
{
    WordNode *current = list.head;
    if (current == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->msize = 0;
        return;
    }
    addFront(current->theWord);
    while (current->next != nullptr)
    {
        current = current->next;
        addBack(current->theWord);
    }
}

/**
 * This is a move constructor for the WordList class that transfers ownership of the head, tail, and
 * size of a list to a new object.
 *
 * @param list A reference to a WordList object that is being moved (i.e. its resources are being
 * transferred to another object). The double ampersand (&&) indicates an rvalue reference, which is
 * used to bind to temporary objects that are about to be moved.
 */
WordList::WordList(WordList &&list)
{
    this->head = list.head;
    list.head = nullptr;
    this->tail = list.tail;
    list.tail = nullptr;
    this->msize = list.msize;
    list.msize = 0;
}

/**
 * This function overloads the assignment operator for a WordList object by copying the contents of
 * another WordList object.
 *
 * @return The WordList object that was assigned to is being returned.
 */
WordList &WordList::operator=(const WordList &rhs)
{
    if (this == &rhs)
        return *this;
    WordNode *current = rhs.head;
    if (current == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->msize = 0;
        return *this;
    }
    addFront(current->theWord);
    while (current->next != nullptr)
    {
        current = current->next;
        addBack(current->theWord);
    }
    return *this;
}

/**
 * This is a move assignment operator for a WordList class in C++.
 *
 * @return a reference to the current object, which is of type `WordList&`.
 */
WordList &WordList::operator=(WordList &&rhs)
{
    if (this == &rhs)
        return *this;
    this->head = rhs.head;
    rhs.head = nullptr;
    this->tail = rhs.tail;
    rhs.tail = nullptr;
    this->msize = rhs.msize;
    rhs.msize = 0;
    return *this;
}

/**
 * The WordList destructor deletes all nodes in the linked list.
 */
WordList::~WordList()
{
    WordNode *current = head;
    while (current != nullptr)
    {
        WordNode *next = current->next;
        delete current;
        current = next;
    }
}

/**
 * This function removes a given node from a linked list of words.
 *
 * @param nodePtr A pointer to a WordNode that needs to be removed from the WordList.
 * @return a boolean value. It returns true if the given node is successfully removed from the linked
 * list, and false otherwise.
 */
bool WordList::remove(WordList::WordNode *nodePtr)
{
    if (nodePtr == nullptr)
        return false;
    WordNode *current = head;
    while (current != nullptr)
    {
        if (current->next == nodePtr)
        {
            current->next = nodePtr->next;
            delete nodePtr;
            return true;
        }
        current = current->next;
    }
    return false;
}

/**
 * The function searches for a given word in a linked list and returns the node containing the word or
 * the node before the insertion point if the word is not found.
 *
 * @param aWord a constant reference to a Word object that is being searched for in the WordList.
 * @return a pointer to a WordNode object. The function is used to search for a specific word in a
 * linked list and returns the node that contains the word or the node that should come before the word
 * if it were to be inserted into the list. If the word is not found and the end of the list is
 * reached, the function returns a pointer to the last node in the list
 */
WordList::WordNode *WordList::lookup(const Word &aWord)
{
    WordNode *current = head;
    WordNode *previous = nullptr;

    while (current != nullptr)
    {
        if (current->theWord.compare(aWord) == 0)
        {
            // Word found in the list, return the node
            return current;
        }
        else if (current->theWord.compare(aWord) > 0)
        {
            // Insertion point found, return the previous node
            return previous;
        }
        previous = current;
        current = current->next;
    }
    // End of list reached, return the last node
    return tail;
}

/**
 * This function adds a new node containing a word to the front of a linked list.
 *
 * @param aWord a constant reference to a Word object that is being added to the front of the WordList.
 */
void WordList::addFront(const Word &aWord)
{
    WordNode *newNode = new WordNode(aWord, head);
    head = newNode;
    if (tail == nullptr)
        tail = newNode;
    msize++;
}

/**
 * This function adds a new node containing a word to the end of a linked list.
 *
 * @param aWord a constant reference to a Word object that is being added to the back of the WordList.
 */
void WordList::addBack(const Word &aWord)
{
    WordNode *newNode = new WordNode(aWord, nullptr);
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    msize++;
}

/**
 * This function adds a new WordNode containing a given Word after a specified WordNode in a WordList.
 *
 * @param p A pointer to a WordNode object that represents the node after which the new node containing
 * the given word should be added.
 * @param aWord a constant reference to a Word object that is being added to the WordList.
 * @return Nothing is being returned explicitly in this function. However, if the `addFront()` function
 * is called, it will return void.
 */
void WordList::addAfter(WordNode *p, const Word &aWord)
{
    if (p == nullptr)
    {
        addFront(aWord);
        return;
    }
    WordNode *newNode = new WordNode(aWord, p->next);
    p->next = newNode;
    if (tail == p)
        tail = newNode;
    msize++;
}

/**
 * This function checks if a WordList object is empty or not.
 *
 * @return a boolean value indicating whether the WordList object is empty or not. If the size of the
 * WordList is 0, then the function returns true, indicating that the WordList is empty. Otherwise, it
 * returns false, indicating that the WordList is not empty.
 */
bool WordList::empty() const
{
    return msize == 0;
}

/**
 * The function returns the size of a WordList object.
 *
 * @return The size of the WordList object, which is stored in the private member variable `msize`.
 */
size_t WordList::size() const
{
    return msize;
}

/**
 * This function prints the words in a linked list to an output stream.
 *
 * @param sout The parameter `sout` is a reference to an output stream object of type `std::ostream`.
 * It is used to output the contents of the `WordList` to the specified output stream.
 */
void WordList::print(std::ostream &sout) const
{
    WordNode *current = head;
    while (current != nullptr)
    {
        sout << current->theWord << std::endl;
        current = current->next;
    }
}

/**
 * This function returns a constant reference to the first word in a linked list of words.
 *
 * @return A constant reference to the first word in the WordList.
 */
const Word &WordList::front() const
{
    return head->theWord;
}

/**
 * This function returns a constant reference to the last word in a linked list of words.
 *
 * @return A constant reference to the `theWord` member variable of the `tail` node in the `WordList`.
 */
const Word &WordList::back() const
{
    return tail->theWord;
}

/**
 * The function adds a word to a sorted list in an alphabetical sorted way.
 *
 * @param aWord a constant reference to a Word object that is being added to the WordList.
 * @return nothing (void).
 */
void WordList::addSorted(const Word &aWord)
{
    WordNode *position = lookup(aWord);

    if (position == nullptr)
    {
        addFront(aWord);
        return;
    }
    if (position->theWord.compare(aWord) == 0)
    { // if the word is already in the list, add lines
        NumList numList = aWord.getNumberList();
        for (int i = 0; i < numList.size(); ++i)
        {
            int value = numList.get(i);
            position->theWord.appendNumber(value);
        }
        return;
    }
    else
    {
        addAfter(position, aWord);
        return;
    }
}

/**
 * This function adds a word and its corresponding line number to a sorted list of words.
 *
 * @param str A constant reference to a string object that contains the word to be added to the
 * WordList.
 * @param lineNum lineNum is an integer parameter that represents the line number where the word
 * appears in a text document. It is used in the WordList class to keep track of the line numbers
 * associated with each word in the list.
 */
void WordList::addSorted(const std::string &str, int lineNum)
{
    addSorted(Word(str.c_str(), lineNum));
}

/**
 * This function removes the first node in a linked list of words and returns true if successful.
 *
 * @return A boolean value indicating whether the removal of the front node was successful or not.
 */
bool WordList::removeFront()
{
    if (head == nullptr)
        return false;
    WordNode *temp = head;
    head = head->next;
    delete temp;
    msize--;
    return true;
}

/**
 * This function removes the last node from a linked list of words.
 *
 * @return A boolean value indicating whether the removal of the last node in the WordList was
 * successful or not.
 */
bool WordList::removeBack()
{
    if (tail == nullptr)
        return false;
    WordNode *current = head;
    while (current->next != tail)
    {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    msize--;
    return true;
}

/**
 * This function searches for a given word in a linked list of words and returns true if found, false
 * otherwise.
 *
 * @param aWord a constant reference to a Word object, which is the word being searched for in the
 * WordList.
 * @return A boolean value is being returned, either true or false.
 */
bool WordList::search(const Word &aWord) const
{
    WordNode *current = head;
    while (current != nullptr)
    {
        if (current->theWord.compare(aWord) == 0)
            return true;
        current = current->next;
    }
    return false;
}

/**
 * This is an overloaded operator function that prints the contents of a WordList object to an output
 * stream.
 *
 * @return The `std::ostream` object `sout` is being returned.
 */
std::ostream &operator<<(std::ostream &sout, const WordList &list)
{
    list.print(sout);
    return sout;
}
