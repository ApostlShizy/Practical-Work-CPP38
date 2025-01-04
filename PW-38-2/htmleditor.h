#ifndef HTMLEDITOR_H
#define HTMLEDITOR_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class HTMLEditor;
}
QT_END_NAMESPACE

class HTMLEditor : public QMainWindow
{
    Q_OBJECT

public:
    HTMLEditor(QWidget *parent = nullptr);

private slots:
    void editHtmlSlot();

private:
    Ui::HTMLEditor *ui;
    QWebEngineView * display;
    QPlainTextEdit * editor;
};
#endif // HTMLEDITOR_H
