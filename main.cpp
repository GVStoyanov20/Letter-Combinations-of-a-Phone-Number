#include <iostream>
#include <vector>
#include <map>

using namespace std;

void generateCombinations(string digits, string combination, int index, vector<string>& result, map<char, vector<char>>& digitsMapping)
{
    if (index == digits.size())
    {
        result.push_back(combination);
        return;
    }

    char digit = digits[index];
    vector<char> letters = digitsMapping[digit];

    for (char letter : letters)
    {
        generateCombinations(digits, combination + letter, index + 1, result, digitsMapping);
    }
}

int main()
{
    map<char, vector<char>> digitsMapping;

    digitsMapping['0'] = {'+', ' '};
    digitsMapping['1'] = {'@'};
    digitsMapping['2'] = {'a', 'b', 'c'};
    digitsMapping['3'] = {'d', 'e', 'f'};
    digitsMapping['4'] = {'g', 'h', 'i'};
    digitsMapping['5'] = {'j', 'k', 'l'};
    digitsMapping['6'] = {'m', 'n', 'o'};
    digitsMapping['7'] = {'p', 'q', 'r', 's'};
    digitsMapping['8'] = {'t', 'u', 'v'};
    digitsMapping['9'] = {'w', 'x', 'y', 'z'};

    string input;
    cout << "Enter numbers separated by spaces: ";
    getline(cin, input);

    vector<string> inputs;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos)
    {
        inputs.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    inputs.push_back(input);

    for (int i = 0; i < inputs.size(); ++i)
    {
        string input = inputs[i];
        vector<string> combinations;
        generateCombinations(input, "", 0, combinations, digitsMapping);
        cout << "All letter combinations for '" << input << "': ";
        cout << "[";
        for (int j = 0; j < combinations.size(); ++j)
        {
            cout << "\"" << combinations[j] << "\"";
            if (j < combinations.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
