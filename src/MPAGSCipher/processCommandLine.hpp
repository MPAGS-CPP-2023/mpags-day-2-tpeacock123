#ifndef MPAGSCIPHER_PCL_HPP
#define MPAGSCIPHER_PCL_HPP

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& cmdLineArgs, 
                        bool& helpRequested, bool& versionRequested, 
                        std::string& inputFile, std::string& outputFile,
                        bool& encrypt, std::string& key);


#endif // MPAGSCIPHER_TRANSFORM_HPP