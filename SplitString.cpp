#include <iostream>
#include <vector>
#include <string>

/* example:
    string: "a b, c"; separator = " ," => vector: {"a", "b", "c"}
    string: "a b, c"; separator = "," => vector: {"a b", "c"}
    string: "a b, c"; separator = ";" => vector: {"a b,c"}
    string: " "; separator = "," => vector: {}
*/

std::vector<std::string> splitString(const std::string& str, const std::string& separator)
{
    std::vector<std::string> tokens;
    
    //skip separator at begining
    std::string::size_type lastPos = str.find_first_not_of(separator, 0);
    
    //find first "non-delimater"
    std::string::size_type pos = str.find_first_of(separator, lastPos);
    
    while(pos != std::string::npos || lastPos != std::string::npos)
    {
        // found a tokens
        tokens.emplace_back(str.substr(lastPos, pos - lastPos));
        
        //skip separator
        lastPos = str.find_first_not_of(separator, pos);
        
        //find next non-separator
        pos = str.find_first_of(separator, lastPos);
    }
    return tokens;
}

int main()
{
    std::string str {"a b, c"};
    std::string separator {","};
    
    std::vector<std::string> outPut = splitString(str, separator);
    int i {0};
    for(const auto& token : outPut)
    {
        std::cout << i << ": ";
        std::cout << token << "\n";
        i++;
    }

    return 0;
}