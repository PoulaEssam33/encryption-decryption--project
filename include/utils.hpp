#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <limits>

void display_menu();

void display_options();

char get_choice();

std::string get_text();

std::string get_key();

std::string cipher_text(std::string text, std::string key);

void print_hex(std::string hex);

std::string get_clear_text(std::string text);

bool is_hexadecimal(const std::string &text);

std::string decrypt_hex(std::string hex, std::string key);

#endif