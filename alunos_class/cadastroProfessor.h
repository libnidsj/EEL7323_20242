#ifndef CADASTROPROFESSOR_H
#define CADASTROPROFESSOR_H

#include "professor.h"
#include <iostream>
#include <string.h>

class cadastroProfessor{
        Professor professor[50];
        int listPosition;
    public:
        cadastroProfessor();
        void incluiProfessor(int, string, string, int);
        bool excluiProfessor(int);
        bool alteraProfessor(int, string, string, int);
        int professorCount();
        Professor returnProfessor(int);
};

#endif