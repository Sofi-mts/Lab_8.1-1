// Lab_8.1(1).cpp
// Лабораторна робота № 8.1. Пошук та заміна символів у літерному рядку.
// Варіант 8. Ітераційний спосіб.
// Виконала: Кучер Софія.
//
// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів всі букви, що входять в слово "while".
// 2. Замінити кожну групу букв "while" парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// чи входить символ c до рядка s
bool ContainsChar(const char* s, const char c)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return true;
    return false;
}

// чи входять до рядка s всі букви слова "while"
bool ContainsAllLetters(const char* s)
{
    const char letters[] = "while";

    for (int j = 0; letters[j] != '\0'; j++)
        if (!ContainsChar(s, letters[j]))
            return false;
    return true;
}

// чи починається з позиції i рядка s група букв "while"
// (перевірка зупиняється на першому розбіжному символі,
//  тому за межі рядка вона не виходить)
bool IsWhileAt(const char* s, const size_t i)
{
    return s[i]     == 'w' &&
           s[i + 1] == 'h' &&
           s[i + 2] == 'i' &&
           s[i + 3] == 'l' &&
           s[i + 4] == 'e';
}

// замінює кожну групу букв "while" парою зірочок "**";
// змінений рядок записується в параметр s і повертається як результат
char* Change(char* s)
{
    size_t len = strlen(s);
    char* tmp = new char[len + 1];   // результат не довший за вихідний рядок
    char* t = tmp;

    size_t i = 0;
    while (s[i] != '\0')
    {
        if (IsWhileAt(s, i))
        {
            *t++ = '*';
            *t++ = '*';
            i += 5;                  // пропускаємо "while"
        }
        else
            *t++ = s[i++];
    }
    *t = '\0';

    strcpy(s, tmp);

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (ContainsAllLetters(str))
        cout << "String contains all letters of \"while\"" << endl;
    else
        cout << "String does not contain all letters of \"while\"" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    system("pause");    // щоб вікно не закривалося одразу
    return 0;
}
