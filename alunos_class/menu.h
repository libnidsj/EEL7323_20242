#ifndef MENU_H
#define MENU_H

#include "cadastroPessoa.h"
#include "cadastroAlunos.h"
#include "cadastroProfessor.h"
#include <iostream>
#include <string.h>

class Menu{
        cadastroPessoa bancoPessoas;
        cadastroAlunos bancoAlunos;
        cadastroProfessor bancoProfessores;
    public:
        void menuPrincipal();

        void listarPessoas();
        void filtrarPessoas();
        void filtrarAlunos();
        void filtrarProfessores();

        void adicionarPessoa();
        void adicionarAluno();
        void adicionarProfessor();

        void procurarPessoa();
        void procurarAluno();

        void editarPessoa();
        void excluirPessoa();
        void procurarProfessor();
        
        void editarAluno();
        void editarProfessor();
        
        void excluirProfessor();
        void excluirAluno();
};

#endif