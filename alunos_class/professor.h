#ifndef PROFESSOR_H
#define PROFESSOR_H

using namespace std;
#include <iostream>
#include "string.h"
#include "pessoa.h"

class Professor: public Pessoa{
        int matricula;
        string materia;
    public:
        void setMateria(string);
        void setMatricula(int);
        string getMateria();
        int getMatricula();
};

#endif