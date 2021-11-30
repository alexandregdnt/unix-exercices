#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <unistd.h>
#include "protocole.h" // contient la cle et la structure d'un message

int idQ;
int pid1,pid2;
void handlerSIGINT(int sig);

int main()
{
  MESSAGE requete, reponse;
  pid_t destinataire;

  // Armement du signal SIGINT
  // TO DO (etape 6)
  fprintf(stderr,"(Traitement %d) Armement du signal SIGINT\n",getpid());
  struct sigaction A;
  A.sa_handler = handlerSIGINT;
  A.sa_flags = 0;
  sigemptyset(&A.sa_mask);
  sigaction(SIGINT,&A,NULL);

  // Creation de la file de message
  fprintf(stderr,"(SERVEUR) Creation de la file de messages\n");
  // TO DO (etape 2)
  idQ = msgget(CLE, IPC_CREAT| 0600);

  // Attente de connection de 2 clients
  fprintf(stderr,"(SERVEUR) Attente de connection d'un premier client...\n");
  // TO DO (etape 5)
  msgrcv(idQ, &requete, sizeof(MESSAGE) - sizeof(long), 1, 0);
  pid1 = requete.expediteur;

  fprintf(stderr,"(SERVEUR) Attente de connection d'un second client...\n");
  // TO DO (etape 5)
  msgrcv(idQ, &requete, sizeof(MESSAGE) - sizeof(long), 1, 0);
  pid2 = requete.expediteur;

  while(1) 
  {
    // TO DO (etapes 3, 4 et 5)
  	fprintf(stderr,"(SERVEUR) Attente d'une requete...\n");
    msgrcv(idQ, &requete, sizeof(MESSAGE) - sizeof(long), 1, 0);
    fprintf(stderr,"(SERVEUR) Requete recue de %d : --%s--\n",requete.expediteur,requete.texte);    
    /*Etape 3
    destinataire = requete.expediteur;
    sprintf(reponse.texte, "(SERVEUR)%s", requete.texte);
    reponse.type = destinataire;
    reponse.expediteur = getpid();
    */
    fprintf(stderr,"(SERVEUR) Envoi de la reponse a %d\n",destinataire);    
    /*Etape3et4
    msgsnd(idQ, &reponse, sizeof(MESSAGE) - sizeof(long), 0);
    */
    if(requete.expediteur == pid1){
      destinataire = pid2;
    }else{
      destinataire = pid1;
    }
    requete.type = destinataire;
    msgsnd(idQ, &requete, sizeof(MESSAGE) - sizeof(long), 0);
    kill(destinataire, SIGUSR1);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO DO (etape 6)
void handlerSIGINT(int sig){
  fprintf(stderr,"(Serveur) Reception du signal SIGINT (%d)\n",sig);
  msgctl(idQ, IPC_RMID, NULL);
  exit(0);
}