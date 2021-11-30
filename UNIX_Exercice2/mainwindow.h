#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setNom(const char* Text);
    void setEmail(const char* Text);
    void setAnneeNaissance(int annee);
    void setPhoto(const char* Text);

    const char* getPhoto();
    const char* getEmail();
    const char* getNom();
    int   getAnneeNaissance();

private slots:
    void on_pushButtonPrecedent_clicked();
    void on_pushButtonSuivant_clicked();
    void on_pushButtonModifier_clicked();
    void on_pushButtonQuitter_clicked();

private:
    Ui::MainWindow *ui;

    char photo[80];
    char email[80];
    char nom[80];
};
#endif // MAINWINDOW_H
