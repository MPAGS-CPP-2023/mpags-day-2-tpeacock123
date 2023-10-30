#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        bool& helpRequested, bool& versionRequested,
                        std::string& inputFile, std::string& outputFile,
                        bool& encrypt, std::string& key) {

    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                return false; // Changed return to indicate failure as a boolean
            } else {
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                return false; // Changed return to indicate failure as a boolean
            } else {
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-k" || cmdLineArgs[i] == "--key") {
            key = cmdLineArgs[i + 1];
            ++i;
        } else if (cmdLineArgs[i] == "-e") {
            encrypt = true;
        } else if (cmdLineArgs[i] == "-d") {
            encrypt = false;
        } else {
            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            return false; // Changed return to indicate failure as a boolean
        }
    }
    return true; // Changed to return true upon successful processing
}