// Copyright [2011] <Tom Leo>

#include <cstring>

#include "wordcount.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

WordCount::WordCount() {}

void WordCount::generate_words(string sentence) {
    string temp = "";
    for ( int i = 0; i <= sentence.size(); ++i ) {
        if (sentence[i] == '\0') {
            if (temp.size() != 0) {
                this->words_.push_back(temp);
            }
            break;
        }
        else if ((sentence[i] == ' ') || (sentence[i] == ',')) {
            if (temp.size() != 0) {
                this->words_.push_back(temp);
            }
            temp = "";
        } else {
            temp+=sentence[i];
        }
    }
}

int WordCount::in_array(string str) {
    int size = this->words_.size();
    for (int i = 0; i < size; i++) {
        if (this->fdic_words_[i].compare(str) == 0) {
            return i;
        }
    }
    return -1;
}

void WordCount::generate_fdic() {
    int size = this->words_.size();
    this->fdic_words_ = new string[size];
    this->fdic_count_ = new int[size];

    for ( int i = 0; i < size; i++ ) {
        int index = this->in_array(this->words_[i]);
        if ( index != -1 ) {
            this->fdic_words_[i] = ",";
            this->fdic_count_[index]+=1;
        } else {
            this->fdic_words_[i] = this->words_.at(i);
            this->fdic_count_[i] = 1;
        }
    }
}

void WordCount::get_wordcounts() {
    int size = this->words_.size();
    for (int i = 0; i < size; i++) {
        if (this->fdic_words_[i] != ",") {
            cout << this->fdic_words_[i] << ":" << this->fdic_count_[i] << endl;
        }
    }
}

int main() {
    string testString = "how, now now now brown cow cow";
    WordCount test;
    test.generate_words(testString);
    test.generate_fdic();
    test.get_wordcounts();
    return 0;
}

