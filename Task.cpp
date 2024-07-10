#include <iostream>
#include <string>
#include <cctype>

// Функция для замены слова в тексте
void replaceWord(std::string& text, const std::string& oldWord, const std::string& newWord) {
    size_t pos = text.find(oldWord);
    while (pos != std::string::npos) {
        text.replace(pos, oldWord.length(), newWord);
        pos = text.find(oldWord, pos + newWord.length());
    }
}

// Функция для капитализации предложений
void capitalizeSentences(std::string& text) {
    bool capitalize = true;
    for (char& ch : text) {
        if (capitalize && std::isalpha(ch)) {
            ch = std::toupper(ch);
            capitalize = false;
        }
        else if (ch == '.' || ch == '?' || ch == '!') {
            capitalize = true;
        }
    }
}

// Функция для подсчета букв
void countLetters(const std::string& text) {
    int letters[26] = { 0 };
    for (char ch : text) {
        if (std::isalpha(ch)) {
            letters[std::tolower(ch) - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (letters[i] != 0) {
            std::cout << static_cast<char>('a' + i) << ": " << letters[i] << "\n";
        }
    }
}

// Функция для подсчета цифр
void countDigits(const std::string& text) {
    int digits[10] = { 0 };
    for (char ch : text) {
        if (std::isdigit(ch)) {
            digits[ch - '0']++;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (digits[i] != 0) {
            std::cout << i << ": " << digits[i] << "\n";
        }
    }
}

int main() {
    std::string text;
    std::string oldWord;
    std::string newWord;

    // Запрос ввода от пользователя
    std::cout << "Enter the text:\n";
    std::getline(std::cin, text);
    std::cout << "Enter the replacement word:\n";
    std::cin >> oldWord;
    std::cin.ignore(); // Очистка входного буфера
    std::cout << "Enter a new word:\n";
    std::getline(std::cin, newWord);

    replaceWord(text, oldWord, newWord);
    capitalizeSentences(text);

    std::cout << "\nUpdated text:\n" << text << "\n\n";

    std::cout << "The number of each letter in the text:\n";
    countLetters(text);

    std::cout << "\nThe number of each digit in the tex:\n";
    countDigits(text);

    return 0;
}