#ifndef CADASTROPESSOA_H
#define CADASTROPESSOA_H

#include "pessoa.h"
#include <iostream>
#include <string.h>

class cadastroPessoa{
        Pessoa pessoa[50];
        int listPosition;
    public:
        cadastroPessoa();
        void incluiPessoa(int, string);
        void excluiPessoa();
        void alteraPessoa();
        int pessoaCount();
        Pessoa returnPessoa(int);
};

#endif