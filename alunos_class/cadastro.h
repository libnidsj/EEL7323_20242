#ifndef CADASTRO_H
#define CADASTRO_H

using namespace std;
#include <iostream>
#include <string.h>
#include "alunos.h"

class Cadastro {
    Alunos aluno;
    int listPosition;
   public:
    Cadastro();
    ~Cadastro();
    bool cadastrarAluno();
    void buscarAluno();
    bool editarAluno();
    bool deletarAluno();
};

#endif