// Copyright (c) 2024 Jan Pydych

#include "Solver.h"
#include "Dictionary.h"

#include <iostream>

using namespace std;

void Solver::solve(Word target) {
    string targetId = sort_letters(target.word);

    for (Word word1 : words) {
        if ((target.mask & word1.mask) == word1.mask) {
            for (Word word2 : words) {
                if ((target.mask & word2.mask) == word2.mask) {
                    string sum = word1.word + word2.word;

                    if (sort_letters(sum) == targetId) {
                        cout << word1.word << " " << word2.word << endl;
                    }
                }
            }
        }
    }
}
