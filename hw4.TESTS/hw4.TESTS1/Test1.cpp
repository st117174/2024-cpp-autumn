#include "TextEditor.h"
#include <gtest/gtest.h>

// Test fixture for TextEditor
class TextEditorTest : public ::testing::Test {
protected:
    TextEditor editor;
};

TEST_F(TextEditorTest, AddTextTest) {
    editor.addText("Hello");
    EXPECT_EQ(editor.getTextWithCursor(), "Hello|");
}

TEST_F(TextEditorTest, DeleteTextTest) {
    editor.addText("Hello");
    int deleted = editor.deleteText(2);
    EXPECT_EQ(deleted, 2);
    EXPECT_EQ(editor.getTextWithCursor(), "Hel|");
}

TEST_F(TextEditorTest, CursorLeftTest) {
    editor.addText("Hello");
    editor.cursorLeft(2);
    EXPECT_EQ(editor.getTextWithCursor(), "Hel|lo");
}

TEST_F(TextEditorTest, CursorRightTest) {
    editor.addText("Hello");
    editor.cursorLeft(3);
    editor.cursorRight(2);
    EXPECT_EQ(editor.getTextWithCursor(), "Hell|o");
}

TEST_F(TextEditorTest, CombinedOperationsTest) {
    editor.addText("Sdelall");
    editor.cursorLeft(2);
    editor.addText(" homeworkyes");
    editor.cursorRight(3);
    editor.deleteText(5);
    EXPECT_EQ(editor.getTextWithCursor(), "Sdelal homework|s");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
