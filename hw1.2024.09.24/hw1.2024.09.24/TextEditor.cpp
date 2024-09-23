#include "TextEditor.h"

TextEditor::TextEditor() {}

void TextEditor::addText(const std::string& text) {
    for (char c : text) {
        leftStack.push(c);
    }
}

int TextEditor::deleteText(int k) {
    int count = 0;
    while (k-- > 0 && !leftStack.empty()) {
        leftStack.pop();
        count++;
    }
    return count;
}

std::string TextEditor::cursorLeft(int k) {
    while (k-- > 0 && !leftStack.empty()) {
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
    return getTextWithCursor();
}

std::string TextEditor::cursorRight(int k) {
    while (k-- > 0 && !rightStack.empty()) {
        leftStack.push(rightStack.top());
        rightStack.pop();
    }
    return getTextWithCursor();
}

std::string TextEditor::getTextWithCursor() {
    return getLeftText() + "|" + getRightText();
}

std::string TextEditor::getLeftText() {
    std::string result;
    std::stack<char> temp = leftStack;
    while (!temp.empty()) {
        result = temp.top() + result;
        temp.pop();
    }
    return result;
}

std::string TextEditor::getRightText() {
    std::string result;
    std::stack<char> temp = rightStack;
    while (!temp.empty()) {
        result += temp.top();
        temp.pop();
    }
    return result;
}

