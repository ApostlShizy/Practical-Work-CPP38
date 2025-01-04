#include "htmleditor.h"
#include "ui_htmleditor.h"

HTMLEditor::HTMLEditor(QWidget *parent): QMainWindow(parent), ui(new Ui::HTMLEditor)
{
    ui->setupUi(this);

    display = ui->htmlDisplay;
    editor = ui->htmlEdit;

    display->setHtml(editor->toPlainText());

    connect(editor,&QPlainTextEdit::textChanged,this,&HTMLEditor::editHtmlSlot);
}

void HTMLEditor::editHtmlSlot()
{
    display->setHtml(editor->toPlainText());
}

