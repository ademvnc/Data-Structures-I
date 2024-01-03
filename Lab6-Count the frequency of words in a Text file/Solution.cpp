#include <stdio.h>
#include <vector>
#include <algorithm>
#include "WordFreq.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;


vector<WordFreq> GetMostFrequentKWords(string filename, int k) {
    vector<WordFreq> wordFrequencies;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: File not found or cannot be opened." << endl;
        return wordFrequencies;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            // Transform to lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            // Remove punctuation
            auto new_end = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
            word.erase(new_end, word.end());

            if (word.size() >= 3) {
                auto it = find_if(wordFrequencies.begin(), wordFrequencies.end(),
                    [word](const WordFreq& wf) { return wf.word == word; });

                if (it != wordFrequencies.end()) {
                    it->freq++;
                }
                else {
                    wordFrequencies.push_back(WordFreq(word));
                }
            }
        }
    }

    sort(wordFrequencies.begin(), wordFrequencies.end(),
        [](const WordFreq& a, const WordFreq& b) {
            if (a.freq != b.freq) {
                return a.freq > b.freq;
            }
            return a.word < b.word;
        });

    k = min(k, static_cast<int>(wordFrequencies.size()));
    vector<WordFreq> result(wordFrequencies.begin(), wordFrequencies.begin() + k);

    return result;
}