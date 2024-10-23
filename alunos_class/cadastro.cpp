#include "cadastro.h"
#include "alunos.h"
using namespace std;

Cadastro::Cadastro() {
    listPosition = 0;
}

Cadastro::~Cadastro() {
    listPosition = 0;
}

bool Cadastro::cadastrarAluno() {
    string nomeBuffer = ""; 
    cin >> nomeBuffer;
    cout << nomeBuffer << endl;
    listPosition++;
}