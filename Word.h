// Copyright (c) 2024 Jan Pydych

#ifndef ANAGRAMSFINDER_WORD_H
#define ANAGRAMSFINDER_WORD_H


#include <string>
#include <utility>
#include <cstdint>
#include <algorithm>

typedef uint64_t WordMask;

inline std::string sort_letters(std::string word) {
    std::string result = "";
    int len = word.length();

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int count = 0;

        for (int i = 0; i < len; i++) {
            if (word[i] == ch) {
                count++;
            }
        }

        for (int i = 0; i < count; i++) {
            result += ch;
        }
    }

    return result;
}

class Word {
public:
    WordMask mask;
    std::string word;

    explicit Word(std::string word) : word(word) {
        mask = mask_for(word);
    }

    static WordMask mask_for(std::string word) {
        WordMask mask = 0;

        for (int i = 0; i < word.length(); i++) {
            WordMask submask = mask_for(word[i]);

            if ((mask & submask) != 0) {
                submask <<= 1;
            }

            mask |= submask;
        }

        return mask;
    }

    static WordMask mask_for(char ch) {
        if (isalpha(ch)) {
            uint8_t idx = tolower(ch) - 'a';

            WordMask mask = ((WordMask) 1) << (idx * 2);

            return mask;
        }

        return 0;
    }
};


#endif //ANAGRAMSFINDER_WORD_H
