#include "alunos.h"
using namespace std;

void Alunos::setMatricula(int newMatricula) {
   matricula = newMatricula;
}

void Alunos::setCurso(string newCurso) {
   curso = newCurso;
}

int Alunos::getMatricula(){
   return matricula;
}
string Alunos::getCurso(){
   return curso;
}