// Copyright (c) 2024 Jan Pydych

#include "Dictionary.h"
#include "Word.h"
#include "Solver.h"

using namespace std;

int main() {
    Dictionary::load("wpolish.txt");

    Word target = Word("uniaeuropejska");

    Solver::solve(target);

    return 0;
}
