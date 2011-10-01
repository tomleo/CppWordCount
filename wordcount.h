// Copyright [2011] <Tom Leo>

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

typedef vector<string>::iterator VecIter;

// Counts the frequency of words in a string.
class WordCount {
 public:
    // All words found from generate_words is added to words_
    vector<string> words_;

    // fdic_words_ is an array of all the words in a sentence without
    // duplicates. fdic_count_ contains the number of times each word in
    // fdic_words_ occors. The two arrays are related based on their index, and
    // are ment to mimic a dictionary.
    string *fdic_words_;
    int    *fdic_count_;

    // Default constructor does do anything
    WordCount();

    // Create a vector of all words in sentence.
    //
    // The deliminators are the comma and period. Boosts tokenizer might be a
    // better solution but this is simple and does not require external
    // libraries.
    void generate_words(string);

    // Returns index of string in member variable fdic_words_ if word is not
    // found returns -1
    int in_array(string);

    // Generates a fake dictionary like structure, where the index of a word
    // is in member variable fdic_words_ and the index of
    // a word count in fdic_count_
    void generate_fdic();

    // Each valid entry (not equal to ',') from fdic_words_ is prited along with
    // the number of times the word accures via fdic_count_
    void get_wordcounts();

    // Returns true if string is present in fdic_words_
    bool find_word(string);
};
