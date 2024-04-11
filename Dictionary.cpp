// Copyright (c) 2024 Jan Pydych

#include "Dictionary.h"
#include "Word.h"

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<Word> words;

void Dictionary::load(const char *name) {
    ifstream dict(name);

    string word;

    while (dict >> word) {
        // TODO: Word length as program parameter
        if (word.length() != 7) {
            continue;
        }

        // TODO: Add support for non-ASCII characters
        if (any_of(word.begin(), word.end(), [](char c) {
                return static_cast<unsigned char>(c) > 127;
            })) {
            continue;
        }

        transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c){ return tolower(c); });

        words.emplace_back(word);
    }
}
