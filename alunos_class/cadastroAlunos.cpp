#include "cadastroAlunos.h"
using namespace std;

#include <iostream>
#include <string.h>

cadastroAlunos::cadastroAlunos() {
    listPosition = 0;
}

void cadastroAlunos::incluiAluno(int novaMatricula, string novoCurso, string novoNome, int novaIdade) {
    aluno[listPosition].setMatricula(novaMatricula);
    aluno[listPosition].setCurso(novoCurso);
    aluno[listPosition].setIdade(novaIdade);
    aluno[listPosition].setNome(novoNome);
    listPosition++;
}

bool cadastroAlunos::excluiAluno(int targetMatricula) {
    int position = 0;
    while(position < listPosition) {
        if(aluno[listPosition].getMatricula() == targetMatricula) {
            break;
        } else {
            position++;
        }
    }

    if(position != listPosition) {
        for(int i = position; i < listPosition; i++){
            aluno[i] = aluno[i + 1];
        }
        position--;
        return 1;
    } else {
        return 0;
    }

}

bool cadastroAlunos::alteraAluno(int targetMatricula, string novoCurso, string novoNome, int novaIdade) {
    int position = 0;
    while(position < listPosition) {
        if(aluno[listPosition].getMatricula() == targetMatricula) {
            break;
        } else {
            position++;
        }
    }

    if(position != listPosition) {
        aluno[listPosition].setCurso(novoCurso);
        aluno[listPosition].setIdade(novaIdade);
        aluno[listPosition].setNome(novoNome);
        return 1;
    } else {
        return 0;
    }

}

int cadastroAlunos::alunosCount() {
    return listPosition;
}

Alunos cadastroAlunos::returnAluno(int targetPosition) {
    return aluno[targetPosition];
}