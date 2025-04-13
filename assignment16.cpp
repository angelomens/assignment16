#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>  

int hexCharToDecimal(char ch) 
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'A' && ch <= 'F')
        return 10 + (ch - 'A');
    else
        throw std::invalid_argument("Invalid hex character found.");
}

int hex2Dec(const std::string& hexString) 
{
    int decimalValue = 0;

    for (char ch : hexString) 
    {
        char upperCh = std::toupper(ch);  
                if (!std::isxdigit(ch))
            {
            throw std::invalid_argument("Input contains non-hex characters.");
            }
        decimalValue = decimalValue * 16 + hexCharToDecimal(upperCh);
    }

    return decimalValue;
}

int main()
{
    std::string hexInput;
    std::cout << "Enter a hexadecimal number: ";
    std::cin >> hexInput;

    try
    {
        int decimalValue = hex2Dec(hexInput);
        std::cout << "Decimal value: " << decimalValue << std::endl;
    }
    catch (const std::invalid_argument& ex) 
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
