#include <cstring>

#include "wordcount.hh"

using namespace std;

WordCount::WordCount(){
    //Does nothing lolz
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
    DictIter di;
    for(VecIter i = this->words_.begin(); i != words_.end(); ++i){
        for(VecIter j = i; j != words_.end(); ++j){
            if((*i).compare(*j) == 0){
                if(this->word_counts_.find(*i)!=di.end){
                    word_counts_[*i]+=1;
                }
                else {
                    word_counts_[*i]=1;
                }
            }
        }
    }
}

int main(){
    string testString = "how, now now now brown cow cow";
    WordCount test;
    test.generate_words(testString);
    return 0;
}

