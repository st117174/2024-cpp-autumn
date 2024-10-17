#include "string.h"

// Конструктор для строки из C-style строки
String::String(const char * str) {
    size = strlen(str);
    this->str = new char[size+1];
    for(size_t i = 0; i <= size; ++i)
        this->str[i] = str[i];
}

// Конструктор для строки из повторяющегося символа
String::String(size_t n, char c): size(n), str(0)
{
    this->str = new char[size + 1];
    for (int i = 0; i < size; this->str[i] = c, ++i);
    str[size] = '\0';
}

// Деструктор
String::~String()
{
    delete[] str;
}

// Конструктор копирования
String::String(const String& other) :size(other.size)
{
    str = new char[size + 1];
    strcpy(str, other.str);
}

// Оператор присваивания
String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[this->size + 1];
        strcpy(this->str, other.str);
    }
    return *this;
}

// Метод для добавления строки
void String::append(const String &other)
{
    size += other.size;
    char* new_str = new char[size + 1];
    strcpy(new_str, str);
    strcat(new_str, other.str);
    delete[] str;
    str = new_str;
}

// Первый оператор [] для выбора начальной позиции i
String::SubString String::operator[](size_t i) const {
    return SubString(*this, i);
}

// Второй оператор [] для выбора конечной позиции j и возврата подстроки
String String::SubString::operator[](size_t end) const {
    // Вычисляем длину подстроки
    size_t new_size = end - start;

    // Создаем новую строку нужной длины
    String result(new_size, '\0');  // временная строка нужного размера
    for (size_t i = 0; i < new_size; ++i) {
        result.str[i] = parent.str[start + i];
    }
    result.str[new_size] = '\0';  // не забываем про завершающий 0

    return result;
}
