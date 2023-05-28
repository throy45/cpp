#include "WordList.h"

WordList::WordList(){};

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

WordList::WordList(WordList &&list)
{
    this->head = list.head;
    list.head = nullptr;
    this->tail = list.tail;
    list.tail = nullptr;
    this->msize = list.msize;
    list.msize = 0;
}

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

void WordList::addFront(const Word &aWord)
{
    WordNode *newNode = new WordNode(aWord, head);
    head = newNode;
    if (tail == nullptr)
        tail = newNode;
    msize++;
}

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

bool WordList::empty() const
{
    return msize == 0;
}

size_t WordList::size() const
{
    return msize;
}

void WordList::print(std::ostream &sout) const
{
    WordNode *current = head;
    while (current != nullptr)
    {
        sout << current->theWord << std::endl;
        current = current->next;
    }
}

const Word &WordList::front() const
{
    return head->theWord;
}

const Word &WordList::back() const
{
    return tail->theWord;
}

// TODO: finish implementing this function
// if the word is present, it should add the line number to the list
// and adjust the frequencies
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

void WordList::addSorted(const std::string &str, int lineNum)
{
    addSorted(Word(str.c_str(), lineNum));
}

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

std::ostream &operator<<(std::ostream &sout, const WordList &list)
{
    list.print(sout);
    return sout;
}
