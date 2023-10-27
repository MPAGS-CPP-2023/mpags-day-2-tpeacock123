#include <iostream>
#include <string>
#include <vector>

std::string TransformChar(const char in_char)
/*
~~~~~~Transform CHAR~~~~~~~ 

    - takes an input Character 
    - if a letter makes it upper case 
    - if a number writes it out as a word
    - ignores anything else
returns upper-case letter or number of word
*/
{
    std::string charstr{""};
    if(std::isalpha(in_char))
    {
        charstr = std::toupper(in_char);
  
    } 

    switch (in_char)
    {
        case '1':
            charstr = "ONE";

            break;

        case '2':
            charstr  = "TWO";

            break;
        
        case '3':
            charstr  = "THREE";

            break;
        
        case '4':
            charstr  = "FOUR";
        
            break; 

        case '5':
            charstr  = "FIVE";
  
            break; 

        case '6':
            charstr  = "SIX";
           
            break;

        case '7':
            charstr  = "SEVEN";
          
            break;  
        case '8':
            charstr  = "EIGHT";
           
            break;  
        case '9':
            charstr  = "NINE";
         
            break; 
        case '0':
            charstr  = "ZERO";
         
            break; 

        default:
            // Do nothing
            break;
    }
    return charstr;
// - Ignore any other (non-alpha) characters
// - In each case, add result to a string variable  
} 

void processCommandLine(const std::vector<std::string>& cmdLineArgs, bool& Help, Bool& Version, std::string& input_file, std::string& output_file)
/* 
~~~~~~ProcessCommandLine~~~~~~~~
input:
-vector containing command line arguments
-empty variables help, input_file and output_file
output:
-nothing, but searches cmdlineargs for occurences of -h,-i,-o 
-if -h is found, help user (turn help = true)
-if -i or -o is found, save next argument as input_file or output_file 
*/
{
    for(int i = 0; i < (cmdLineArgs.size()); i++)
    {
        if(cmdLineArgs[i] == "-h" ||cmdLineArgs[i] == "--help"){
            Help = true; 
        }
        if(cmdLineArgs[i] == "-v" ||cmdLineArgs[i] == "--version"){
            Version = true; 
        }

        if(cmdLineArgs[i] == "-i"){
            input_file = cmdLineArgs[i+1];
        }

        if(cmdLineArgs[i] == "-o"){
            output_file = cmdLineArgs[i+1];
        }

    }
}

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs {argv, argv+argc};

    std::string input_file{""};
    std::string output_file{""};
    bool Help = false;
    bool Version = false;

    processCommandLine(cmdLineArgs, Help, input_file, output_file);

    std::cout << Help << "\n";
    std::cout << input_file << "\n";
    std::cout << output_file << "\n";
    
    char in_char{'x'};
    std::string out_str{""};

    // Take each letter from user input and in each case:
    while(std::cin >> in_char)
    {
        out_str += TransformChar(in_char);
    }
    // print out the new string
    std::cout << out_str << std::endl;
    
}