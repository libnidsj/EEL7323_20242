#include "cadastroPessoa.h"
using namespace std;

#include <iostream>
#include <string.h>

cadastroPessoa::cadastroPessoa() {
    listPosition = 0;
}

void cadastroPessoa::incluiPessoa(int novaIdade, string novoNome) {
    pessoa[listPosition].setIdade(novaIdade);
    pessoa[listPosition].setNome(novoNome);
    listPosition++;
}

void cadastroPessoa::excluiPessoa() {

}

void cadastroPessoa::alteraPessoa() {

}

int cadastroPessoa::pessoaCount() {
    return listPosition;
}

Pessoa cadastroPessoa::returnPessoa(int targetPosition) {
    return pessoa[targetPosition];
}