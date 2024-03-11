// Name: Poula Essam Kamal
// ID: 20230098
// Section: 15
#include <iostream>
#include <cctype>
#include <iomanip>
#include "../include/utils.hpp"

int main()
{
    char choice = ' ', choiceOption = ' ';
    std::string text = "", key = "", new_text = "", hexString = "";
    bool exit_program = false;
    while (!exit_program)
    {
        display_menu();
        choice = get_choice();
        switch (choice)
        {
        case 'A':
            while (true)
            {
                text = get_text();
                key = get_key();
                if (key.empty())
                {
                    std::cout << "Key cannot be empty!" << std::endl;
                    continue;
                }
                new_text = cipher_text(text, key);
                std::cout << "Cipher text: " << new_text << std::endl;
                print_hex(new_text);
                break;
            }
            break;
        case 'B':
            display_options();
            choiceOption = get_choice();
            switch (choiceOption)
            {
            case 'A':
                new_text.clear();
                while (true)
                {
                    std::string clear_text;
                    std::cout << "Enter your Encrypted text in hexa: ";
                    std::getline(std::cin, text);
                    std::cout << "Enter the secret key: ";
                    std::getline(std::cin, key);
                    if (key.empty())
                    {
                        std::cout << "\nKey cannot be empty" << std::endl;
                        continue;
                    }

                    clear_text = get_clear_text(text);

                    if(!is_hexadecimal(clear_text))
                    {
                        std::cout << "Invalid hexa input" << std::endl;
                        continue;
                    }

                    new_text = decrypt_hex(clear_text, key);

                    std::cout << "Plain text: " << new_text;
                    std::cout << std::endl;
                    break;
                }
                break;
            case 'B':
                new_text.clear();
                while (true)
                {
                    text = get_text();
                    key = get_key();
                    if (key.empty())
                    {
                        std::cout << "Key cannot be empty!" << std::endl;
                        continue;
                    }
                    new_text = cipher_text(text, key);
                    std::cout << "Plain text: " << new_text << std::endl;
                    break;
                }
                break;
            case 'C':
                std::cout << "Going back to the menu...\n";
                break;
            default:
                std::cout << "Please enter valid input\n";
                break;
            }
            break;
        case 'C':
            exit_program = true;
            std::cout << "Exiting the program... please wait...\n";
            break;
        default:
            std::cout << "Please enter valid input\n";
            break;
        }
    }
    return 0;
}
