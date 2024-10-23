#include "pessoa.h"
#include "string.h"
using namespace std;

void Pessoa::setNome(string novoNome){
    nome = novoNome;
}

void Pessoa::setIdade(int novaIdade){
    idade = novaIdade;
}

string Pessoa::getNome(){
    return nome;
}

int Pessoa::getIdade(){
    return idade;
}