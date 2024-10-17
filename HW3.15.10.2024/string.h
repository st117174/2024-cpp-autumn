#include <iostream>
#include <cstddef>  // size_t
#include <cstring>  // strlen, strcpy

struct String {
    public:
        String(const char *str = "");
        String(size_t n, char c);
        ~String();

        String(const String &other);
        String &operator=(const String &other);

        void append(const String &other);

        // Оператор [] для получения подстроки
        struct SubString {
            const String& parent;  // ссылка на исходную строку
            size_t start;          // начальная позиция i

            SubString(const String& parent, size_t start) : parent(parent), start(start) {}

            // Второй оператор [] для получения подстроки между i и j
            String operator[](size_t end) const;
        };

        SubString operator[](size_t i) const; // Первый оператор []
        
    private:
        size_t size;
        char *str;
};
