#include <cctype>
#include <iostream>
#include <string>
#include <list>
#include <vector>

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string output_str{""};
  

    for(char c : inputText){
        for(int i = 0 ; i < 27; i++)  {
            if( alphabet[i] == c){
                if(encrypt){
                    int new_pos = (i + key) % 26;
                    char new_char = alphabet[new_pos];
                    output_str.push_back(new_char);
                } else if(!encrypt) {
                    int new_pos = (i - key + 26) % 26;
                    char new_char = alphabet[new_pos];
                    output_str.push_back(new_char);
                }
            }
        }
    }
    return output_str; 
}


