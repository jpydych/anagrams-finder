# AnagramsFinder

AnagramsFinder is a program developed by Jan Pydych
for solving anagram puzzles.

# Puzzle

This anagram puzzle divides a 14-letter passphrase into two 7-letter words 
that are part of the original string.
For example, the passphrase "uniaeuropejska" can be divided into words "aaronie" and "skupuje".

# Algorithm

AnagramsFinder employs a search algorithm that iterates through all seven-letter words 
in a dictionary (the default is wpolish, but it can be changed in the main.cpp file). For each word, it 
generates a 64-bit mask (in practice, only 52 bits are used, where even bits indicate that a letter occurs 
at least once, and odd bits indicate the letter occurs twice or more). Then it checks if a given word
is a part of the passphrase. If so, it searches through all the words again and checks if they also belong
to the passphrase, displaying all pairs of words that meet the puzzle criteria.

# Usage

To use AnagramsFinder, follow these steps:

* Compile the program using CMake.
* Download a dictionary file containing one word per line, without spaces or other characters, 
  and without empty lines. By default, the program expects a file named "wpolish.txt" in the working directory.
* Adjust the passphrase string and the dictionary filename in the main.cpp file, if needed.
* Run the compiled executable.
* View the output displaying the pairs of words that meet the puzzle criteria.

# Benchmarks

AnagramsFinder was benchmarked using the wpolish dictionary (20240101-1) with the passphrase "uniaeuropejska". 
The program searched through 90,324,931 words (computational complexity: O(n<sup>2</sup>)) on an Intel Core i7-10700KF 
processor, taking 1418ms.

# License

This program is licensed under the MIT License - see the LICENSE file for details.
