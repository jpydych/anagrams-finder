// Copyright (c) 2024 Jan Pydych

#include "Solver.h"
#include "Dictionary.h"

#include <iostream>
#include <chrono>

// #define BENCHMARK

using namespace std;

void Solver::solve(Word target) {
    string targetId = sort_letters(target.word);

#ifdef BENCHMARK
    auto start_time = chrono::high_resolution_clock::now();
    auto searched = 0;
#endif

    for (const auto& word1 : words) {
        if ((target.mask & word1.mask) == word1.mask) {
            for (const auto& word2 : words) {
                if (word1.word == word2.word) {
                    continue;
                }

                if ((target.mask & word2.mask) == word2.mask) {
                    string sum = word1.word + word2.word;

                    if (sort_letters(sum) == targetId) {
                        cout << word1.word << " " << word2.word << endl;
                    }
                }

#ifdef BENCHMARK
                searched++;
#endif
            }
        }

#ifdef BENCHMARK
        searched++;
#endif
    }

#ifdef BENCHMARK
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    std::cout << endl << "solve(" << target.word << ") took " <<
              time/std::chrono::milliseconds(1) << "ms to run. " <<
              searched << " words searched." << endl;
#endif
}
