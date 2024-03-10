// Name: Poula Essam Kamal
// ID: 20230098
// Section: 15
#include <iostream>
#include <cctype>
#include <iomanip>


using namespace std;
int main() {

    while (true){
    cout << "\"Welcome to Xor Cipher\"" << "\n";
    cout << "A) Encrypt     B) Decrypt     C)Exit \n";
    cout << "Your choice: ";
    char choice;
    cin >> choice;
    choice = toupper(choice);
    cin.ignore();
    string text;
    string key;
    string new_text ="";
    if(choice=='A'){
        while (true){

        cout << "Enter your text: ";
        getline(cin, text);
        cout << "Enter the secret key: ";
        getline(cin, key);
        if (key.empty()) {
            cout << "Key cannot be empty!" << endl;
            continue;
        }
        for (int i=0; i < text.length(); i++) {
            char char_new_text= text[i]^ key[i % key.length()] ;
            new_text += char_new_text ;
        }
        cout << "Cipher text: "<< new_text;


        cout << "\n" << "Hexa:";
        if (new_text.length() % 2 == 0) {
            for (int s = 0; s < text.length(); s++) {
                cout << hex << " " << setw(2) << setfill('0') << int(new_text[s]);
            }
        }
        else {
            for (int s = 0; s < text.length(); s++) {
                cout << hex << " " << int(new_text[s]);
            }
        }
        cout << endl;
        break;
        }
    }

    else if(choice=='B'){
        while (true){

        cout << "A)Hexadecimal Decrypt     B)Text Decrypt \n " << "Your choice: ";
        char choice2;
        cin >> choice2;
        choice2 = toupper(choice2);
        cin.ignore();
        if ( choice2 == 'A'){
            while (true){
                string clear_text;
                cout << "Enter your Encrypted text in hexa: ";
                getline(cin, text);
                cout  << "Enter the secret key: ";
                getline(cin, key);
                if (key.empty()) {
                    cout << "\nKey cannot be empty" << endl;
                    continue;
                }

                for(int j=0; j<text.length(); j++){
                    if (isalnum(text[j])) {
                        clear_text += text[j];
                    }
                }
                bool is_hexadecimal = true;
                for (char c : clear_text) {
                    if (!isxdigit(c)) {
                        is_hexadecimal = false;
                        break;
                    }
                }

                if (!is_hexadecimal) {
                    cout << "Please enter input in hexadecimal format" << endl;
                    continue;
                }

                for (int i = 0; i < clear_text.length(); i += 2) {
                    int byte = stoi(clear_text.substr(i, 2), nullptr, 16);
                    char decrypted_char = byte ^ key[i / 2 % key.length()];
                    new_text += decrypted_char;
                }

                cout << "Plain text: " << new_text;
                cout << endl ;
                break;
            }
            break;
        }
        else if (choice2 == 'B'){
            while (true) {

                cout << "Enter your text: ";
                getline(cin, text);
                cout << "Enter the secret key: ";
                getline(cin, key);
                if (key.empty()) {
                    cout << "Key cannot be empty!" << endl;
                    continue;
                }
                for (int i = 0; i < text.length(); i++) {
                    char char_new_text = text[i] ^ key[i % key.length()];
                    new_text += char_new_text;
                }
                cout << "Plain text: " << new_text << endl;
                break;
            }
            break;

        }
        else{
            cout << "Please enter valid input \n";
        }
        }
    }
    else if(choice == 'C'){
        cout << "Thanks!";
        break;
    }
    else{
        cout << "Please enter valid input \n";
    }
    }
    return 0;
}
