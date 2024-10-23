#include "menu.h"
using namespace std;
#include <iostream>
#include <string.h>
#include "pessoa.h"
#include "alunos.h"
#include "professor.h"

void Menu::menuPrincipal() {
    int menuSwitch = 0;

    cout << endl;

    cout << "Escolha a funcao desejada conforme o menu abaixo" << endl;

    cout << endl;

    cout << "1- Listar usuarios" << endl;
    cout << "2- Listar pessoas comuns" << endl;
    cout << "3- Listar alunos" << endl;
    cout << "4- Listar professores" << endl;

    cout << endl;

    cout << "5- Adicionar pessoa comum" << endl;
    cout << "6- Adicionar aluno" << endl;
    cout << "7- Adicionar professor" << endl;

    cout << endl;

    cout << "Opcao desejada: ";
    cin >> menuSwitch;
    cout << endl;

    switch(menuSwitch) {
        case 1:
            listarPessoas();
            break;
        case 2:
            filtrarPessoas();
            break;
        case 3:
            filtrarAlunos();
            break;
        case 4:
            filtrarProfessores();
            break;
        case 5:
            adicionarPessoa();
            break;
        case 6:
            adicionarAluno();
            break;
        case 7:
            adicionarProfessor();
            break;
        default:
            cout << "Escolha uma opcao valida." << endl;
    }

}

void Menu::listarPessoas() {
    for(int i = 0; i < 3; i++) {
        Pessoa pessoaDummy;
        Alunos alunoDummy;
        Professor professorDummy;
        int pessoasCount = 0;
        switch(i){
            case 0:
                cout << endl << "Pessoas comuns" << endl;
                pessoasCount = bancoPessoas.pessoaCount();
                for(int j = 0; j < pessoasCount; j++) {
                    pessoaDummy = bancoPessoas.returnPessoa(j);
                    cout << "- Nome: " << pessoaDummy.getNome() << " | Idade: " << pessoaDummy.getIdade() << endl;
                }
                break;
            case 1:
                cout << endl << "Alunos" << endl;
                pessoasCount = bancoAlunos.alunosCount();
                for(int j = 0; j < pessoasCount; j++) {
                    alunoDummy = bancoAlunos.returnAluno(j);
                    cout << "- Nome: " << alunoDummy.getNome() << " | Idade: " << alunoDummy.getIdade() << " | Curso: " << alunoDummy.getCurso() << " | Matricula: " << alunoDummy.getMatricula() << endl;
                }
                break;
            case 2:
                cout << endl << "Professores" << endl;
                pessoasCount = bancoProfessores.professorCount();
                for(int j = 0; j < pessoasCount; j++) {
                    professorDummy = bancoProfessores.returnProfessor(j);
                    cout << "- Nome: " << professorDummy.getNome() << " | Idade: " << professorDummy.getIdade() << " | Materia: " << professorDummy.getMateria() << " | Matricula: " << professorDummy.getMatricula() << endl;
                }
                break;
        }
    }
}

void Menu::filtrarPessoas() {
    Pessoa pessoaDummy;
    int pessoasCount = 0;
    cout << endl << "Pessoas comuns" << endl;
    pessoasCount = bancoPessoas.pessoaCount();
    for(int j = 0; j < pessoasCount; j++) {
        pessoaDummy = bancoPessoas.returnPessoa(j);
        cout << "- Nome: " << pessoaDummy.getNome() << " | Idade: " << pessoaDummy.getIdade() << endl;
    }
}

void Menu::filtrarAlunos() {
    Alunos alunoDummy;
    int pessoasCount = 0;
    cout << endl << "Alunos" << endl;
    pessoasCount = bancoAlunos.alunosCount();
    for(int j = 0; j < pessoasCount; j++) {
        alunoDummy = bancoAlunos.returnAluno(j);
        cout << "- Nome: " << alunoDummy.getNome() << " | Idade: " << alunoDummy.getIdade() << " | Curso: " << alunoDummy.getCurso() << " | Matricula: " << alunoDummy.getMatricula() << endl;
    }
} 

void Menu::filtrarProfessores() {
    Professor professorDummy;
    int pessoasCount = 0;
    cout << endl << "Professores" << endl;
    pessoasCount = bancoProfessores.professorCount();
    for(int j = 0; j < pessoasCount; j++) {
        professorDummy = bancoProfessores.returnProfessor(j);
        cout << "- Nome: " << professorDummy.getNome() << " | Idade: " << professorDummy.getIdade() << " | Materia: " << professorDummy.getMateria() << " | Matricula: " << professorDummy.getMatricula() << endl;
    }
}

void Menu::adicionarPessoa() {
    string nomeBuffer = "";
    int idadeBuffer = 0;
    string cursoBuffer = "";
    int matriculaBuffer = 0;
    cout << "Digite o nome da pessoa: ";
    cin >> nomeBuffer;
    cout << "Digite a idade da pessoa: ";
    cin >> idadeBuffer;
    bancoPessoas.incluiPessoa(idadeBuffer, nomeBuffer);
}

void Menu::procurarPessoa() {

}

void Menu::adicionarAluno() {
    string nomeBuffer = "";
    int idadeBuffer = 0;
    string cursoBuffer = "";
    int matriculaBuffer = 0;
    cout << "Digite o nome do aluno: ";
    cin >> nomeBuffer;
    cout << "Digite a idade do aluno: ";
    cin >> idadeBuffer;
    cout << "Digite o curso do aluno: ";
    cin >> cursoBuffer;
    cout << "Digite a matricula do aluno: ";
    cin >> matriculaBuffer;
    bancoAlunos.incluiAluno(matriculaBuffer, cursoBuffer, nomeBuffer, idadeBuffer);
}

void Menu::editarAluno() {

}

void Menu::adicionarProfessor() {
    string nomeBuffer = "";
    int idadeBuffer = 0;
    string materiaBuffer = "";
    int matriculaBuffer = 0;
    cout << "Digite o nome do professor: ";
    cin >> nomeBuffer;
    cout << "Digite a idade do professor: ";
    cin >> idadeBuffer;
    cout << "Digite a materia do professor: ";
    cin >> materiaBuffer;
    cout << "Digite a matricula do professor: ";
    cin >> matriculaBuffer;
    bancoProfessores.incluiProfessor(matriculaBuffer, materiaBuffer, nomeBuffer, idadeBuffer);
}