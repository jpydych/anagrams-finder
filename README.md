# AnagramsFinder

AnagramsFinder is a program developed by Jan Pydych 
for solving an anagram puzzle.

# Puzzle

The anagram puzzle consists of dividing 
a 14-letter passphrase into two 7-letter words 
that are part of the original string.
For example, the passphrase "uniaeuropejska" can be 
divided into "aaronie" and "skupuje".

# Algorithm

AnagramsFinder employs a search algorithm that
iterates through all seven-letter words 
in a dictionary (default is wpolish, but can be 
changed in the main.cpp file). For each word, it 
generates a 64-bit mask (in practice, only 52 bits 
are used, where even bits indicate the occurrence of 
a letter at least once, and odd bits indicate the occurrence
of a letter at least twice). Then, it checks if a given word
is part of the passphrase (e.g., "uniaeuropejska"). If so,
it searches through all the words again and checks 
if they also belong to the passphrase, displaying 
all pairs of words that meet the puzzle criteria.

# Usage

To use AnagramsFinder, follow these steps:

* Compile the program using CMake.
* Download a dictionary file containing one word per line, without spaces or other characters, 
  and without empty lines. By default, the program expects a file named "wpolish.txt" in the working directory.
* Adjust the passphrase string and dictionary filename in the main.cpp file, if needed.
* Run the compiled executable.
* View the output displaying the pairs of words that meet the puzzle criteria.

# License

This program is licensed under the MIT License - see the LICENSE file for details.
