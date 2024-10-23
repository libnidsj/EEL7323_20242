#include "professor.h"
#include <string.h>

void Professor::setMatricula(int newMatricula) {
   matricula = newMatricula;
}

void Professor::setMateria(string novaMateria){
    materia = novaMateria;
}

int Professor::getMatricula(){
   return matricula;
}

string Professor::getMateria(){
    return materia;
}