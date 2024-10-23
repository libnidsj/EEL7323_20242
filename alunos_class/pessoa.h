#ifndef PESSOA_H
#define PESSOA_H

using namespace std;
#include <iostream>
#include <string.h>

class Pessoa{
    private:
        string nome;
        int idade;
    public:
        void setNome(string);
        void setIdade(int);
        string getNome();
        int getIdade();
        
};

#endif