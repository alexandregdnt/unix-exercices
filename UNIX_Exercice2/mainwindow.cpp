#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct {
    char nom[40];
    char email[40];
    int anneeNaissance;
    char photo[40];
} ELEMENT;

ELEMENT Elm;
int file = open("individus.dat", O_RDWR);
int i = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    lseek(file, sizeof(ELEMENT) * i, SEEK_SET);
    read(file, &Elm, sizeof(ELEMENT));

    setNom(Elm.nom);
    setEmail(Elm.email);
    setAnneeNaissance(Elm.anneeNaissance);
    setPhoto(Elm.photo);
}

MainWindow::~MainWindow() {
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setNom(const char *Text) {
    fprintf(stderr, "---%s---\n", Text);
    if (strlen(Text) == 0) {
        ui->lineEditNom->clear();
        return;
    }
    ui->lineEditNom->setText(Text);
}

void MainWindow::setEmail(const char *Text) {
    fprintf(stderr, "---%s---\n", Text);
    if (strlen(Text) == 0) {
        ui->lineEditEmail->clear();
        return;
    }
    ui->lineEditEmail->setText(Text);
}

void MainWindow::setAnneeNaissance(int annee) {
    char Text[20];
    sprintf(Text, "%d", annee);
    fprintf(stderr, "---%s---\n", Text);
    if (strlen(Text) == 0) {
        ui->lineEditAnneeNaissance->clear();
        return;
    }
    ui->lineEditAnneeNaissance->setText(Text);
}

void MainWindow::setPhoto(const char *Text) {
    fprintf(stderr, "---%s---\n", Text);
    if (strlen(Text) == 0) {
        ui->lineEditPhoto->clear();
        return;
    }
    ui->lineEditPhoto->setText(Text);

    // Affichage de la photo a droite
    char nomFichier[256];
    sprintf(nomFichier, "./photos/%s", Text);
    QPixmap Pix(nomFichier);
    ui->labelImage->setPixmap(Pix);
    ui->labelImage->setScaledContents(true);
}

const char *MainWindow::getPhoto() {
    if (ui->lineEditPhoto->text().size()) {
        strcpy(photo, ui->lineEditPhoto->text().toStdString().c_str());
        return photo;
    }
    return NULL;
}

const char *MainWindow::getEmail() {
    if (ui->lineEditEmail->text().size()) {
        strcpy(email, ui->lineEditEmail->text().toStdString().c_str());
        return email;
    }
    return NULL;
}

const char *MainWindow::getNom() {
    if (ui->lineEditNom->text().size()) {
        strcpy(nom, ui->lineEditNom->text().toStdString().c_str());
        return nom;
    }
    return NULL;
}

int MainWindow::getAnneeNaissance() {
    if (ui->lineEditAnneeNaissance->text().size()) {
        char tmp[40];
        strcpy(tmp, ui->lineEditAnneeNaissance->text().toStdString().c_str());
        return atoi(tmp);
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButtonPrecedent_clicked() {
    fprintf(stderr, "Clic sur le bouton <<<\n");
    // TO DO

    if (i == 0)
        // i = sizeof(Elm)/sizeof(ELEMENT) - 1;
        i = i;
    else
        i--;

    lseek(file, sizeof(ELEMENT) * i, SEEK_SET);
    read(file, &Elm, sizeof(ELEMENT));

    setNom(Elm.nom);
    setEmail(Elm.email);
    setAnneeNaissance(Elm.anneeNaissance);
    setPhoto(Elm.photo);
}

void MainWindow::on_pushButtonSuivant_clicked() {
    fprintf(stderr, "Clic sur le bouton >>>\n");
    // TO DO

    // if(i == sizeof(Elm)/sizeof(ELEMENT) - 1)
    if (i == 3)
        i = i;
    else
        i++;

    lseek(file, sizeof(ELEMENT) * i, SEEK_SET);
    read(file, &Elm, sizeof(ELEMENT));

    setNom(Elm.nom);
    setEmail(Elm.email);
    setAnneeNaissance(Elm.anneeNaissance);
    setPhoto(Elm.photo);
}

void MainWindow::on_pushButtonModifier_clicked() {
    // Ligne 67 et 74 en commentaire pour modifier le nom et l'année de naissance
    fprintf(stderr, "Clic sur le bouton Modifier\n");
    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Modifier...", "Etes-vous certain de vouloir modifier cet enregistrement ?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes) {
        fprintf(stderr, "Confirmation de modification\n");
        // TO DO

        strcpy(Elm.nom, getNom());
        Elm.anneeNaissance = getAnneeNaissance();
        strcpy(Elm.email, getEmail());
        strcpy(Elm.photo, getPhoto());

        setNom(Elm.nom);
        setAnneeNaissance(Elm.anneeNaissance);
        setEmail(Elm.email);
        setPhoto(Elm.photo);

        lseek(file, sizeof(ELEMENT) * i, SEEK_SET);
        write(file, &Elm, sizeof(ELEMENT));
    }
    else
    {
        lseek(file, sizeof(ELEMENT) * i, SEEK_SET);
        read(file, &Elm, sizeof(ELEMENT));

        setNom(Elm.nom);
        setEmail(Elm.email);
        setAnneeNaissance(Elm.anneeNaissance);
        setPhoto(Elm.photo);
    }
}

void MainWindow::on_pushButtonQuitter_clicked() {
    fprintf(stderr, "Clic sur le bouton Quitter\n");
    // TO DO

    ::close(file);
    exit(0);
}
