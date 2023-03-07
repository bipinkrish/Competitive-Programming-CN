
#include <iostream>
#include <string>

std::string removeConsecutiveDuplicates(std::string str)
{
    // If the length of the string is 0 or 1, there are no duplicates to remove
    if (str.length() <= 1)
    {
        return str;
    }

    // Recursively remove consecutive duplicates from the substring after the first character
    std::string smallerOutput = removeConsecutiveDuplicates(str.substr(1));

    // If the first character of the string is the same as the first character of the smaller output,
    // then we need to discard the first character and return the smaller output.
    if (str[0] == smallerOutput[0])
    {
        return smallerOutput;
    }

    // Otherwise, concatenate the first character with the smaller output and return the result.
    else
    {
        return str[0] + smallerOutput;
    }
}

void removeConsecutiveDuplicates(char *input)
{
    // Convert the input character array to a string
    std::string str(input);

    // Call the removeConsecutiveDuplicates function on the string
    std::string result = removeConsecutiveDuplicates(str);

    // Convert the result string back to a character array and copy it to the input array
    result.copy(input, result.length());
    input[result.length()] = '\0';
}