// WordList.h
#ifndef WORDLIST_H_
#define WORDLIST_H_

#include "Word.h"
#include <iostream>
#include <string>
#include <cstring>

class WordList
{
    // Applying the principle of information hiding, our WordList class will hide the fact that it
    // uses a linked-list of word nodes to implement a word list:
    struct WordNode // a private "member type", a type the client code knows nothing about
    {
        Word theWord;   // the word contained in this node
        WordNode *next; // Pointer to the next node or nullptr

        // special member functions
        // a normal ctor; the only way to creat a word node
        WordNode(const Word &aWord, WordNode *next = nullptr) : theWord(aWord), next(next) {}
        WordNode() = delete;                      // can’t use default ctor
        WordNode(const WordNode &other) = delete; // can’t copy construct a node
        WordNode(WordNode &&other) = delete;      // can’t move construct a node

        WordNode &operator=(const WordNode &other) = delete; // can’t assign a node
        WordNode &operator=(WordNode &&other) = delete;      // can’t move a node
        virtual ~WordNode() = default;
    }; // end of class WordNode
    // begin class WordList
    WordNode *head{nullptr};                       // points to the first node in the list
    WordNode *tail{nullptr};                       // points to the last node in the list
    size_t msize{0};                               // counts the number of noded in the list
    bool remove(WordNode *nodePtr);                // removes the node pointed to by nodePtr
    WordNode *lookup(const Word &aWord);           // returns a pointer to the node containing aWord or to the corresponding insertion spot
    void addFront(const Word &aWord);              // adds a new node containing aWord to the front of the list
    void addBack(const Word &aWord);               // adds a new node containing aWord to the back of the list
    void addAfter(WordNode *p, const Word &aWord); // adds a new node containing aWord after the node pointed to by p

public:
    WordList();
    WordList(const WordList &list);
    WordList(WordList &&list);
    WordList &operator=(const WordList &rhs);
    WordList &operator=(WordList &&rhs);
    virtual ~WordList();
    bool empty() const;
    size_t size() const;
    void print(std::ostream &sout) const;
    const Word &front() const;
    const Word &back() const;
    void addSorted(const Word &aWord);
    void addSorted(const std::string &str, int lineNum);
    bool removeFront();
    bool removeBack();
    bool search(const Word &aWord) const;
    friend std::ostream &operator<<(std::ostream &sout, const WordList &list);
};

#endif