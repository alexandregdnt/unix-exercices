#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

typedef struct
{
  char nom[40];
  char email[40];
  int  anneeNaissance;
  char photo[40];
} ELEMENT;

ELEMENT ElmExemple[] = 
{
  {"Achile Talon","achile.talon@gmail.com",1963,"Achile.jpg"},
  {"Gaston Lagaffe","gaston.lagaffe@gmail.com" , 1957,"Gaston.jpg"},
  {"Lucien","lucien@hepl.be",1979,"Lucien.jpg"},
  {"Robert Bidochon","robert.bidochon@hepl.com", 1977,"Bidochon.jpeg"}
};

int main () {
  const char *cheminFichier = "individus.dat";
  int file;

  if ((file = open(cheminFichier, O_CREAT | O_WRONLY, 0644)) != -1)
  {
    write(file, ElmExemple, sizeof(ElmExemple));
    close(file);
  } 
  else 
  {
    perror("Erreur de open()"); 
    exit(1);
  }

  return 0;
}