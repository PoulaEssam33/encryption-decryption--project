#include "../include/utils.hpp"

void display_menu()
{
    std::cout << "\"Welcome to Xor Cipher\"\n";
    std::cout << "A) Encrypt     B) Decrypt     C)Exit \n";
    std::cout << "Your choice: ";
}

void display_options()
{
    std::cout << "A)Hexadecimal Decrypt     B)Text Decrypt\n";
    std::cout << "C)Go back to the menu\n";
    std::cout << "Your choice: ";
}

char get_choice()
{
    char choice;
    std::cin >> choice;
    choice = toupper(choice);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

std::string get_text()
{
    std::string text;
    std::cout << "Enter your text: ";
    std::getline(std::cin, text);
    return text;
}

std::string get_key()
{
    std::string key;
    std::cout << "Enter the secret key: ";
    std::getline(std::cin, key);
    return key;
}

std::string cipher_text(std::string text, std::string key)
{
    std::string new_text = "";
    size_t key_length = key.length();
    for (size_t i = 0; i < text.length(); i++)
    {
        char encrypted_char = text[i] ^ key[i % key_length];
        new_text.push_back(encrypted_char);
    }
    return new_text;
}


void print_hex(std::string hex)
{
    std::cout << "Hexa:";
    if (hex.length() % 2 == 0)
    {
        for (size_t s = 0; s < hex.length(); s++)
        {
            std::cout << std::hex << " " << std::setw(2) << std::setfill('0') << int(hex[s]);
        }
    }
    else
    {
        for (size_t s = 0; s < hex.length(); s++)
        {
            std::cout << std::hex << " " << int(hex[s]);
        }
    }
    std::cout << std::endl;
}

std::string get_clear_text(std::string text)
{
    std::string clear_text = "";
    for (size_t j = 0; j < text.length(); j++)
    {
        if (isalnum(text[j]))
        {
            clear_text += text[j];
        }
    }
    return clear_text;
}

bool is_hexadecimal(const std::string &text)
{
    for (char c : text)
    {
        if (!isxdigit(c))
        {
            return false;
        }
    }
    return true;
}

std::string decrypt_hex(std::string hex, std::string key)
{
    std::string clear_text = "";
    size_t key_length = key.length();
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        int byte = std::stoi(hex.substr(i, 2), 0, 16);
        char decrypted_char =  byte ^ key[i / 2 % key_length];
        clear_text.push_back(decrypted_char);
    }
    return clear_text;
}