

#include <iostream>
#include "TextEditor.h"


int main(int argc, char* argv[]) {
    TextEditor editor;

    editor.addText("Sdelall ");
    std::cout << editor.getTextWithCursor() << std::endl;

    editor.cursorLeft(2);
    std::cout << editor.getTextWithCursor() << std::endl;

    editor.addText(" homeworkyes");
    std::cout << editor.getTextWithCursor() << std::endl;

    editor.cursorRight(3);
    std::cout << editor.getTextWithCursor() << std::endl;

    editor.deleteText(5);
    std::cout << editor.getTextWithCursor() << std::endl;

    return EXIT_SUCCESS;
}
