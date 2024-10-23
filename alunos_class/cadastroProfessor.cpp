#include "cadastroProfessor.h"
using namespace std;

#include <iostream>
#include <string.h>

cadastroProfessor::cadastroProfessor() {
    listPosition = 0;
}

void cadastroProfessor::incluiProfessor(int novaMatricula, string novaMateria, string novoNome, int novaIdade) {
    professor[listPosition].setMatricula(novaMatricula);
    professor[listPosition].setMateria(novaMateria);
    professor[listPosition].setIdade(novaIdade);
    professor[listPosition].setNome(novoNome);
    listPosition++;
}

bool cadastroProfessor::excluiProfessor(int targetMatricula) {
    int position = 0;
    while(position < listPosition) {
        if(professor[listPosition].getMatricula() == targetMatricula) {
            break;
        } else {
            position++;
        }
    }

    if(position != listPosition) {
        for(int i = position; i < listPosition; i++){
            professor[i] = professor[i + 1];
        }
        position--;
        return 1;
    } else {
        return 0;
    }
}

bool cadastroProfessor::alteraProfessor(int targetMatricula, string novaMateria, string novoNome, int novaIdade) {
    int position = 0;
    while(position < listPosition) {
        if(professor[listPosition].getMatricula() == targetMatricula) {
            break;
        } else {
            position++;
        }
    }

    if(position != listPosition) {
        professor[listPosition].setMateria(novaMateria);
        professor[listPosition].setIdade(novaIdade);
        professor[listPosition].setNome(novoNome);
        return 1;
    } else {
        return 0;
    }
}

int cadastroProfessor::professorCount() {
    return listPosition;
}

Professor cadastroProfessor::returnProfessor(int targetPosition) {
    return professor[targetPosition];
}