#ifndef CADASTROALUNOS_H
#define CADASTROALUNOS_H

#include "alunos.h"
#include <iostream>
#include <string.h>

class cadastroAlunos{
        Alunos aluno[50];
        int listPosition;
    public:
        cadastroAlunos();
        void incluiAluno(int, string, string, int);
        bool excluiAluno(int);
        bool alteraAluno(int, string, string, int);
        int alunosCount();
        Alunos returnAluno(int);
};

#endif