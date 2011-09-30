#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, int> Dict;
typedef Dict::const_iterator DictIter;
typedef std::vector<std::string>::iterator VecIter;

class WordCount{
public:
    std::vector<std::string> words_;
    Dict word_counts_;

    WordCount();

    ///Create a vector of all words in sentence
    void generate_words(std::string);
    
    ///1. breaks sentence into words
    // 2. compares all words against eachother
    // 3. creates a hash word:int count
    void get_wordcounts();

};

