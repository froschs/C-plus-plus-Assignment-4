#include <iostream>
#include <fstream>
#include <string.h>

using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::endl;

void searchFunction(string path, string term);
void sortAsc(string path);
void sortDesc(string path);
int ctoi (char c);
void countFunction(string path);

int main(int argc, char *argv[]) {
    string file_path = "";
    if (argv[1]) {
        file_path = static_cast<string>(argv[1]);
    }
    if (static_cast<string>(argv[2]) == "search") {
        if (argv[3]) {
            string search_term = static_cast<string>(argv[3]);
            searchFunction(file_path, search_term);
        }
    } else if (static_cast<string>(argv[2]) == "sort") {
        if (static_cast<string>(argv[3]) == "asc") {
            sortAsc(file_path);
        }
        else if(static_cast<string>(argv[3]) == "desc") {
            sortDesc(file_path);
        }
    } else if (static_cast<string>(argv[2]) == "count") {
        countFunction(file_path);
    }
    return 0;
}

void searchFunction(string path, string term) {
    ifstream input;
    input.open(path);
    ofstream output;
    output.open("results.txt", ios::app);
    output << "\nResults of Search:" << endl;
    string str;
    int position = 0;
    int line = 0;
    while (getline(input, str)){
        position = str.find(term, 0);
            while (position >= 0) {
                output << "Search term '" << term << "' starts at line " << line << " position " << position << endl;
                position++;
                position = str.find(term, position);
            }
        line++;
    }
    input.close();
    output.close();
}

void sortAsc(string path) {
    ifstream input;
    input.open(path);
    ofstream output;
    output.open("results.txt", ios::app);
    output << "\nResults of Sorting in Ascending Order:" << endl;
    string str;
    while (getline(input, str)) {
        if (isdigit(str[0])) {
            int length = str.size();
            int *numbers = new int[length];
            char *tokens = strtok((char *) str.c_str(), " ");
            int counter = 0;
            while (tokens) {
                numbers[counter++] = ctoi(*tokens);
                tokens = strtok(NULL, " ");
            }
            int startScan, minIndex, minValue;
            for (startScan = 0; startScan < (counter - 1); startScan++) {
                minIndex = startScan;
                minValue = numbers[startScan];
                for (int index = startScan + 1; index < counter; index++) {
                    if (numbers[index] < minValue) {
                        minValue = numbers[index];
                        minIndex = index;
                    }
                }
                numbers[minIndex] = numbers[startScan];
                numbers[startScan] = minValue;
            }
            for (int i = 0; i < counter; i++) {
                output << numbers[i] << " ";
            }
            delete(numbers);
            delete(tokens);
            output << endl;
        } else if (isalpha(str[0])) {
            output << str << endl;
        }
    }
    input.close();
    output.close();
}

void sortDesc(string path) {
    ifstream input;
    input.open(path);
    ofstream output;
    output.open("results.txt", ios::app);
    output << "\nResults of Sorting in Descending Order:" << endl;
    string str;
    while (getline(input, str)) {
        if (isdigit(str[0])) {
            int length = str.size();
            int *numbers = new int[length];
            char *tokens = strtok((char *) str.c_str(), " ");
            int counter = 0;
            while (tokens) {
                numbers[counter++] = ctoi(*tokens);
                tokens = strtok(NULL, " ");
            }
            int startScan, minIndex, maxValue;
            for (startScan = 0; startScan < (counter - 1); startScan++) {
                minIndex = startScan;
                maxValue = numbers[startScan];
                for (int index = startScan + 1; index < counter; index++) {
                    if (numbers[index] > maxValue) {
                        maxValue = numbers[index];
                        minIndex = index;
                    }
                }
                numbers[minIndex] = numbers[startScan];
                numbers[startScan] = maxValue;
            }
            for (int i = 0; i < counter; i++) {
                output << numbers[i] << " ";
            }
            delete(numbers);
            delete(tokens);
            output << endl;
        } else if (isalpha(str[0])) {
            output << str << endl;
        }
    }
    input.close();
    output.close();
}

int ctoi(char c) {
    return c - '0';
}

void countFunction(string path) {
    ifstream input;
    input.open(path);
    string str = "";
    int position = 0;
    int array_position = 0;
    char first_char = '0';
    char second_char = '0';
    const int SIZE = 106;
    int count = 0;
    char char_array[SIZE];
    int count_array[SIZE];
    while (getline(input, str)) {
        int length = str.size();
        while (position < length) {
            if (isalnum(str[position])) {
                first_char = str.at(position);
                char_array[array_position] = first_char;
                for (int i = position + 1; i < length; i++) {
                    second_char = str.at(i);
                    if (first_char == second_char) {
                        count++;
                    }
                }
                count_array[array_position] = count;
                position++;
                array_position++;
                count = 0;
            } else {
                position++;
            }
        }
    }
    int startScan, minIndex, maxValue;
    char maxChar;
    for (startScan = 0; startScan < (SIZE - 1); startScan++) {
        minIndex = startScan;

        maxValue = count_array[startScan];
        for (int index = startScan + 1; index < SIZE; index++) {
            if (count_array[index] > maxValue) {
                maxValue = count_array[index];
                maxChar = char_array[index];
                minIndex = index;
            }
        }
        count_array[minIndex] = count_array[startScan];
        char_array[minIndex] = char_array[startScan];
        count_array[startScan] = maxValue;
        char_array[startScan] = maxChar;
    }
    input.close();

    ofstream output;
    output.open("results.txt", ios::app);
    output << "\nResults of Count:" << endl;
    output << "The most common character is " << char_array[0] << " it is used " << count_array[0] << " times" << endl;
    output << "The least common character is " << char_array[105] << " it is used " << count_array[105] << " times" << endl;

    output.close();
}