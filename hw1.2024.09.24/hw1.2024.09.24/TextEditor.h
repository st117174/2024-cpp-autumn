#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <stack>
#include <string>

class TextEditor {
private:
    std::stack<char> leftStack;
    std::stack<char> rightStack;

public:
    TextEditor();

    void addText(const std::string& text);
    int deleteText(int k);

    std::string cursorLeft(int k);

    std::string cursorRight(int k);

    std::string getTextWithCursor();

private:
    std::string getLeftText();

    std::string getRightText();
};

#endif

