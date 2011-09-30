#include <cstring>

#include "wordcount.hh"

using namespace std;

WordCount::WordCount(){
    //Does nothing lolz
}

bool WordCount::find_word(string word){
    dict::map_by<key>::const_iterator is = this->word_counts_.by<key>().find(word);
    if (is != this->word_counts_.by<key>().end()){
        return 1;
    }
    else {
        return 0;
    }
}

void WordCount::generate_words(string sentence){
//    const char temp_array = sentence.c_str();
//    int size = sizeof(sentence)/sizeof(*sentence);
    string temp = "";
    for(int i=0; i<=sentence.size(); ++i){
        if (sentence[i] == '\0'){
            if(temp.size() != 0){
//                cout << "DEBUG: " << temp << endl;
                this->words_.push_back(temp);
            }
//            cout << "Hitting the breaks" << endl;
            break;
        }
        else if ((sentence[i] == ' ') || (sentence[i] == ',')){
            if(temp.size() != 0){
                this->words_.push_back(temp);
            }
            temp = "";
        }
        else {
            temp+=sentence[i];
        }
    }

    //check if this works
//    vector<string>::iterator VecIter;
/*    int j = 0;
    for(VecIter i = words_.begin(); i != words_.end(); ++i){
//        cout << ++j << endl;
        cout << *i << endl;
    }*/
}

void WordCount::get_wordcounts(){
    dict::map_by<key>::const_iterator is;
    //= this->word_counts_.by<key>().find(word);
    int end = this->words_.size();
    for(int i=0; i<end; i++){
        /*if(this->find_word(this->words_[i])){
            this->word_counts_.push_back( keyVal(this->words_[i] ) );
        }*/
        is = this->word_counts_.by<key>().find(this->words_[i]);
        if(is != this->word_counts_.by<key>().end()){
//            this->word_counts_.push_back( keyVal(this->words_[i]));
              //is->get<value>(this->words_[i])++;
              //this->words_[i].left->value=10;
              try {
                this->word_counts_.left.at(this->words_[i]) = 100;
              } catch (std::out_of_range & e){}
        }
        else {
            this->word_counts_.push_back( keyVal(this->words_[i], 1));
        }
    }
}

/*void WordCount::get_wordcounts(){
    //DictIter di;
    for(VecIter i = this->words_.begin(); i != words_.end(); ++i){
        for(VecIter j = i; j != words_.end(); ++j){
            //If two words match
            if((*i).compare(*j) == 0){
                //If word already in dictionary, add 1 to dict value
                if(this->word_counts_.find(*i)!=di.end){
                    this->word_counts_.left.find(*i)
                }
                //Else add word as new key to dictionary
                else {
                    //word_counts_[*i]=1;
                    word_counts_.push_back( keyVal( *i, 1));
                }
            }
        }
    }
}*/

int main(){
    string testString = "how, now now now brown cow cow";
    WordCount test;
    test.generate_words(testString);
    cout << "FINISHED" << endl;
    return 0;
}

