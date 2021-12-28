#include <iostream>
#include <string>       // used for input string
#include <vector>       // used for characters' counter array

using namespace std;

// use another data structure to complete the task:
bool isUnique_withDS(string sentence)
{
    bool is_unique = true;      // boolean variable to be returned
    
    vector<int> char_counter;   // for capital and small letters
    
    // initialize counter array with 0s:
    for (int i=0; i<(2*26); i++)
    {
        char_counter.push_back(0);
    }

    // loop through all the characters in the given sentence:
    for (int i=0; i<sentence.length(); i++)
    {
        // get decimal value of the character:
        int char_decimal = int(sentence[i]);
        int char_index = 0;

        // skip space [' '] characters:
        if (!(sentence[i] == ' '))
        {
            // see if the character is a capital letter (A -> Z) or a small letter (a -> z):
            if (char_decimal >= int('a'))
            {
                // it's a small letter:
                // NOTE: (6) is the number of letters in between Z and a in ASCII table
                char_index = char_decimal - int('A') - 6;
            }
            else
            {
                // it's a capital letter:
                char_index = char_decimal - int('A');
            }

            cout << "char: " << sentence[i] << "\t with char_index: " << char_index << "\t and ascii: " << char_decimal << endl;

            // this character counter is still (0), which means we did NOT see it before:
            if (char_counter[char_index] == 0)
            {
                char_counter[char_index] += 1;
                continue;
            }

            // the if statement is false, then we did see the character before:
            cout << "Exiting ::" << endl;
            cout << "index: " << i << " ::: " << "char: " << sentence[i] << endl;
            is_unique = false;
            break;
        }
    }
    return is_unique;
}

bool isUnique_withoutDS(string sentence)
{
    bool is_unique = true;
    for (int i=0; i<sentence.length()-1; i++)
    {
        for (int j=i+1; j<sentence.length(); j++)
        {
            if (sentence[i] == sentence[j])
            {
                is_unique = false;
                cout << "Exiting ::" << endl;
                cout << "second_index\t: " << j << " ::: " << "char: " << sentence[j] << endl;
                break;
            }
        }
        if (!is_unique)
        {
            cout << "first_index\t: " << i << " ::: " << "char: " << sentence[i] << endl;
            break;
        }
    }

    return is_unique;
}

int main()
{
    string sentence;
    cout << "enter a sentence: ";
    getline(cin, sentence);

    cout << "\n" << "Is (\"" << sentence << "\") unique? ..." << endl;

    // bool is_unique = isUnique_withDS(sentence);
    bool is_unique = isUnique_withoutDS(sentence);

    string result = "True";
    if (!is_unique)
    {
        result = "False";
    }
    cout << "The result is: \t<<" << result << ">>" << endl << endl;

    return 0;
}