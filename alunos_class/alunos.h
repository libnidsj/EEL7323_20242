#ifndef ALUNOS_H
#define ALUNOS_H

using namespace std;
#include <iostream>
#include <string.h>
#include "pessoa.h"

class Alunos: public Pessoa {
      int matricula;
      string curso;
   public:
      void setMatricula(int newMatricula);
      void setCurso(string newCurso);
      int getMatricula();
      string getCurso();
};

#endif