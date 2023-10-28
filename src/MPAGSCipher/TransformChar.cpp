#include <cctype>
#include <iostream>
#include <string>

std::string TransformChar(const char inputChar){
/*
~~~~~~Transform CHAR~~~~~~~ 

    - takes an input Character 
    - if a letter makes it upper case 
    - if a number writes it out as a word
    - ignores anything else
returns upper-case letter or number of word
*/   
    std::string inputText;
    // Uppercase alphabetic characters
    if (std::isalpha(inputChar)) {
        inputText = std::toupper(inputChar);
    }

    // Transliterate digits to English words
    switch (inputChar) {
        case '0':
            inputText += "ZERO";
            break;
        case '1':
            inputText += "ONE";
            break;
        case '2':
            inputText += "TWO";
            break;
        case '3':
            inputText += "THREE";
            break;
        case '4':
            inputText += "FOUR";
            break;
        case '5':
            inputText += "FIVE";
            break;
        case '6':
            inputText += "SIX";
            break;
        case '7':
            inputText += "SEVEN";
            break;
        case '8':
            inputText += "EIGHT";
            break;
        case '9':
            inputText += "NINE";
            break;
    }
    // If the character isn't alphabetic or numeric, DONT add it   
    return inputText;
}