#include "windowclient.h"
#include "ui_windowclient.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

extern WindowClient *w;

#include "protocole.h" // contient la cle et la structure d'un message

extern char nomClient[40];
int idQ; // identifiant de la file de message

void handlerSIGUSR1(int sig);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
WindowClient::WindowClient(QWidget *parent):QMainWindow(parent),ui(new Ui::WindowClient)
{
  ui->setupUi(this);
  setWindowTitle(nomClient);

  // Recuperation de l'identifiant de la file de messages
  fprintf(stderr,"(CLIENT %s %d) Recuperation de l'id de la file de messages\n",nomClient,getpid());
  // TO DO (etape 2)
  idQ = msgget(CLE, 0);
  // Envoi d'une requete d'identification
  // TO DO (etape 5)
  MESSAGE m;
  m.type = 1;
  m.expediteur = getpid();
  strcpy(m.texte, "");
  msgsnd(idQ, &m, sizeof(MESSAGE) - sizeof(long), 0);

  // Armement du signal SIGUSR1
  // TO DO (etape 4)
  struct sigaction A;
  A.sa_handler = handlerSIGUSR1;
  A.sa_flags = 0;
  sigemptyset(&A.sa_mask);
  sigaction(SIGUSR1,&A,NULL);
}

WindowClient::~WindowClient()
{
  delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowClient::setRecu(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditRecu->clear();
    return;
  }
  ui->lineEditRecu->setText(Text);
}

void WindowClient::setAEnvoyer(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditEnvoyer->clear();
    return;
  }
  ui->lineEditEnvoyer->setText(Text);
}

const char* WindowClient::getAEnvoyer()
{
  if (ui->lineEditEnvoyer->text().size())
  { 
    strcpy(aEnvoyer,ui->lineEditEnvoyer->text().toStdString().c_str());
    if (strlen(aEnvoyer) <= 0)
        strcpy(aEnvoyer, "vide");

    return aEnvoyer;
  }
  return NULL;
}

const char* WindowClient::getRecu()
{
  if (ui->lineEditRecu->text().size())
  { 
    strcpy(recu,ui->lineEditRecu->text().toStdString().c_str());
    return recu;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowClient::on_pushButtonEnvoyer_clicked()
{
  fprintf(stderr,"Clic sur le bouton Envoyer\n");
  // TO DO (etapes 2, 3, 4)
  MESSAGE m1;

  m1.type = 1;
  m1.expediteur = getpid();
  strcpy(m1.texte, getAEnvoyer());
  msgsnd(idQ, &m1, sizeof(MESSAGE) - sizeof(long), 0);
  setAEnvoyer("");
  /*
  etape2
  MESSAGE m2;
  msgrcv(idQ, &m2, sizeof(MESSAGE) - sizeof(long), 1, 0);
  setRecu(m2.texte);
  */
  /*
  etape3
  MESSAGE m2;
  msgrcv(idQ, &m2, sizeof(MESSAGE) - sizeof(long), getpid(), 0);
  setRecu(m2.texte);
  */
}

void WindowClient::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO DO (etape 4)
void handlerSIGUSR1(int sig){
  MESSAGE m2;
  fprintf(stderr,"(CLIENT %s %d) Reception du signal SIGUSR1 (%d)\n",nomClient, getpid(),sig);
  msgrcv(idQ, &m2, sizeof(MESSAGE) - sizeof(long), getpid(), 0);
  w->setRecu(m2.texte);
}
