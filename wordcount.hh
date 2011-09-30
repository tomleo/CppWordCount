#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <boost/config.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>

struct key {};
struct value {};

using namespace boost::bimaps;

/*typedef boost::bimap<std::string, int> Dict;
typedef Dict::value_type keyValue;*/
typedef bimap<
    unordered_set_of< tagged< std::string, key > >,
    unordered_set_of< tagged< int, value > >,
    list_of_relation
> dict;
typedef dict::value_type keyVal;

typedef std::vector<std::string>::iterator VecIter;

class WordCount{
public:
    std::vector<std::string> words_;
    dict word_counts_;

    WordCount();

    ///Create a vector of all words in sentence
    void generate_words(std::string);
    
    ///1. breaks sentence into words
    // 2. compares all words against eachother
    // 3. creates a hash word:int count
    void get_wordcounts();

    bool find_word(std::string);

};

