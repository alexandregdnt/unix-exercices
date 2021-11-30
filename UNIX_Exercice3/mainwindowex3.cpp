#include "mainwindowex3.h"
#include "ui_mainwindowex3.h"
#include <QMessageBox>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int file;

MainWindowEx3::MainWindowEx3(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindowEx3)
{
    ui->setupUi(this);

    file = open("Trace.log", O_RDWR | O_CREAT | O_TRUNC, 644);
    dup2(file, 2);
}

MainWindowEx3::~MainWindowEx3()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx3::setGroupe1(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe1->clear();
    return;
  }
  ui->lineEditGroupe1->setText(Text);
}

void MainWindowEx3::setGroupe2(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe2->clear();
    return;
  }
  ui->lineEditGroupe2->setText(Text);
}

void MainWindowEx3::setGroupe3(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe3->clear();
    return;
  }
  ui->lineEditGroupe3->setText(Text);
}

void MainWindowEx3::setResultat1(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat1->clear();
    return;
  }
  ui->lineEditResultat1->setText(Text);
}

void MainWindowEx3::setResultat2(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat2->clear();
    return;
  }
  ui->lineEditResultat2->setText(Text);
}

void MainWindowEx3::setResultat3(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat3->clear();
    return;
  }
  ui->lineEditResultat3->setText(Text);
}

bool MainWindowEx3::recherche1Selectionnee()
{
  return ui->checkBoxRecherche1->isChecked();
}

bool MainWindowEx3::recherche2Selectionnee()
{
  return ui->checkBoxRecherche2->isChecked();
}

bool MainWindowEx3::recherche3Selectionnee()
{
  return ui->checkBoxRecherche3->isChecked();
}

const char* MainWindowEx3::getGroupe1()
{
  if (ui->lineEditGroupe1->text().size())
  { 
    strcpy(groupe1,ui->lineEditGroupe1->text().toStdString().c_str());
    return groupe1;
  }
  return NULL;
}

const char* MainWindowEx3::getGroupe2()
{
  if (ui->lineEditGroupe2->text().size())
  { 
    strcpy(groupe2,ui->lineEditGroupe2->text().toStdString().c_str());
    return groupe2;
  }
  return NULL;
}

const char* MainWindowEx3::getGroupe3()
{
  if (ui->lineEditGroupe3->text().size())
  { 
    strcpy(groupe3,ui->lineEditGroupe3->text().toStdString().c_str());
    return groupe3;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx3::on_pushButtonLancerRecherche_clicked()
{
  fprintf(stderr,"Clic sur le bouton Lancer Recherche\n");
  // TO DO
    pid_t idFils1, idFils2, idFils3, status, id;

    if (recherche1Selectionnee()) {
        if ((idFils1 = fork()) == -1) {
            perror("Erreur: Fork Fils 1");
            // exit(-1);
        }
        if (idFils1 == 0) {
            execl("./Lecture", "Lecture", getGroupe1(), NULL);
        }
    }

    if (recherche2Selectionnee()) {
        if ((idFils2 = fork()) == -1) {
            perror("Erreur: Fork Fils 2");
            // exit(-1);
        }
        if (idFils2 == 0) {
            execl("./Lecture", "Lecture", getGroupe2(), NULL);
        }
    }

    if (recherche3Selectionnee()) {
        if ((idFils3 = fork()) == -1) {
            perror("Erreur: Fork Fils 3");
            // exit(-1);
        }
        if (idFils3 == 0) {
            execl("./Lecture", "Lecture", getGroupe3(), NULL);
        }
    }

    while ((id = wait(&status)) != -1) {
        if (recherche1Selectionnee() && id == idFils1) {
            if (WIFEXITED(status)) {
                setResultat1(WEXITSTATUS(status));
            }
        }

        if (recherche2Selectionnee() && id == idFils2) {
            if (WIFEXITED(status)) {
                setResultat2(WEXITSTATUS(status));
            }
        }

        if (recherche3Selectionnee() && id == idFils3) {
            if (WIFEXITED(status)) {
                setResultat3(WEXITSTATUS(status));
            }
        }
    }
}

void MainWindowEx3::on_pushButtonVider_clicked()
{
  fprintf(stderr,"Clic sur le bouton Vider\n");
  // TO DO

    setGroupe1("");
    setGroupe2("");
    setGroupe3("");
    setResultat1(0);
    setResultat2(0);
    setResultat3(0);
}

void MainWindowEx3::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  // TO DO
  ::close(file);
  exit(0);
}
