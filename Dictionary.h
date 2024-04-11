// Copyright (c) 2024 Jan Pydych

#ifndef ANAGRAMSFINDER_DICTIONARY_H
#define ANAGRAMSFINDER_DICTIONARY_H

#include <string>
#include <vector>

#include "Word.h"

extern std::vector<Word> words;

class Dictionary {
public:
    static void load(const char *name);
};

#endif //ANAGRAMSFINDER_DICTIONARY_H
