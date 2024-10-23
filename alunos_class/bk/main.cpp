#include <string>
#include <iostream>
#include <limits>
using namespace std;

#define LISTSIZE 10

class Alunos {
      string nome;
      int matricula;
      string curso;
   public:
      Alunos();
      ~Alunos();
      void setNome(string novoNome);
      void setMatricula(int newMatricula);
      void setCurso(string newCurso);
      string getNome();
      int getMatricula();
      string getCurso();
};

Alunos::Alunos() {
   nome = "";
   matricula = 0;
   curso = "";
}
Alunos::~Alunos() {
   nome = "";
   matricula = 0;
   curso = "";
}

void Alunos::setNome(string newNome) {
   nome = newNome;
}

void Alunos::setMatricula(int newMatricula) {
   matricula = newMatricula;
}

void Alunos::setCurso(string newCurso) {
   curso = newCurso;
}

string Alunos::getNome(){
   return nome;
}
int Alunos::getMatricula(){
   return matricula;
}
string Alunos::getCurso(){
   return curso;
}

int main() {
   Alunos aluno[LISTSIZE];
   int alunosCount = 0;

   aluno[alunosCount].setNome("Libni da Silva Junior");
   aluno[alunosCount].setMatricula(21102178);
   aluno[alunosCount].setCurso("Engenharia Eletronica");
   alunosCount++;

   aluno[alunosCount].setNome("Aluno Teste 1");
   aluno[alunosCount].setMatricula(1);
   aluno[alunosCount].setCurso("Engenharia X");
   alunosCount++;

   aluno[alunosCount].setNome("Aluno Teste 2");
   aluno[alunosCount].setMatricula(2);
   aluno[alunosCount].setCurso("Engenharia Y");
   alunosCount++;

   aluno[alunosCount].setNome("Aluno Teste 3");
   aluno[alunosCount].setMatricula(3);
   aluno[alunosCount].setCurso("Engenharia Z");
   alunosCount++;

   int selectBuffer = 0;
   int matriculaBuffer = 0;
   string nomeBuffer = "";
   string cursoBuffer = "";

   while(1){
       cout << "Dentre a lista abaixo, escolha a funcao desejada" << endl;
       cout << "1 - Adicionar aluno" << endl;
       cout << "2 - Buscar aluno" << endl;
       cout << "3 - Editar aluno" << endl;
       cout << "4 - Deletar aluno" << endl;
       cout << "5 - Sair" << endl;
       cout << "Opcao desejada: ";
       cin >> selectBuffer;
       int alunoPositionBuffer = LISTSIZE + 1;
       int loopBreak = 0;

       switch(selectBuffer){
            case 1:
                cout << "Digite o nome do aluno: ";
                cin >> nomeBuffer;
                aluno[alunosCount].setNome(nomeBuffer);
                cout << "Digite o numero de matricula do aluno: ";
                cin >> matriculaBuffer;
                for(int i = 0; i < alunosCount; i++){
                    if(matriculaBuffer == aluno[i].getMatricula()){
                        cout << "Esse numero de matricula ja existe." << endl;
                        loopBreak = 1;
                        break;
                    }
                }
                if(loopBreak == 0){
                   aluno[alunosCount].setMatricula(matriculaBuffer);
                    cout << "Digite o curso do aluno: ";
                    cin >> cursoBuffer;
					//getline(cin, cursoBuffer);
                    aluno[alunosCount].setCurso(cursoBuffer);
                    cout << "Aluno " << nomeBuffer << " adicionado com sucesso" << endl;
                    alunosCount++; 
                } else {
                    loopBreak = 0;
                }
                break;
            case 2:
                cout << "Digite o numero de matricula do aluno: ";
                cin >> matriculaBuffer;
                for(int i = 0; i < alunosCount; i++) {
                    if(matriculaBuffer == aluno[i].getMatricula()) {
                        alunoPositionBuffer = i;
                        break;
                    }
                }
                if(alunoPositionBuffer != LISTSIZE + 1) {
                    cout << "O aluno de numero de matricula " << matriculaBuffer << " possui nome " << aluno[alunoPositionBuffer].getNome() << " e eh do curso " << aluno[alunoPositionBuffer].getCurso() << " ." << endl;
                } else {
                    cout << "Aluno nao foi encontrado." << endl;
                }
                break;
            case 3:
                cout << "Digite o numero de matricula do aluno que deseja editar: ";
                cin >> matriculaBuffer;

                for(int i = 0; i < alunosCount; i++) {
                    if(matriculaBuffer == aluno[i].getMatricula()) {
                        alunoPositionBuffer = i;
                        break;
                    }
                }

                if(alunoPositionBuffer != LISTSIZE + 1) {
                    while(1){
                        cout << "Digite 1 para editar o nome do aluno, 2 para editar o curso e 3 para sair: ";
                        cin >> selectBuffer;
                        switch(selectBuffer){
                            case 1:
                                cout << "O antigo nome do aluno eh: " << aluno[alunoPositionBuffer].getNome() << ". Digite o novo nome desejado: ";
                                cin >> nomeBuffer;
								//getline(cin, nomeBuffer);
                                aluno[alunoPositionBuffer].setNome(nomeBuffer);
                                cout << "O nome do aluno de matricula " << matriculaBuffer << " foi alterado para " << nomeBuffer << endl;
                                break;
                            case 2:
                                cout << "O antigo curso do aluno eh: " << aluno[alunoPositionBuffer].getCurso() << ". Digite o novo curso desejado: ";
                                cin >> cursoBuffer;
								//getline(cin, cursoBuffer);
                                aluno[alunoPositionBuffer].setCurso(cursoBuffer);
                                cout << "O curso do aluno de matricula " << matriculaBuffer << " foi alterado para " << cursoBuffer << endl;
                                break;
                            case 3:
                                loopBreak = 1;
                                break;
                            default:
                                cout << "Opcao invalida";
                        }
                        if(loopBreak == 1) {
                            loopBreak = 0;
                            break;
                        }
                    }

                } else {
                    cout << "Aluno nao foi encontrado." << endl;
                }


                break;
            case 4:
                cout << "Digite o numero de matricula do aluno que deseja deletar: ";
                cin >> matriculaBuffer;

                for(int i = 0; i < alunosCount; i++) {
                    if(matriculaBuffer == aluno[i].getMatricula()) {
                        alunoPositionBuffer = i;
                        break;
                    }
                }

                if(alunoPositionBuffer != LISTSIZE + 1) {
                    for(int i = alunoPositionBuffer; i < alunosCount - 1; i++) {
                        aluno[i] = aluno[i + 1];
                    }
                    aluno[alunosCount].~Alunos();
                    alunosCount--;
                    cout << "O aluno de numero de matricula " << matriculaBuffer << " foi deletado." << endl;
                } else {
                    cout << "Aluno nao foi encontrado." << endl;
                }

                break;
            case 5:
                loopBreak = 1;
                break;
            default:
                for(int i = 0; i < alunosCount; i++) {
                    cout << aluno[i].getMatricula() << endl;
                }
                cout << "Opcao invalida" << endl;

            }
            if(loopBreak == 1){
                break;
       }
   }

}
