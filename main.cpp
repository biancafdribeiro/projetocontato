#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    Data() {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
    void setDia(int dia) {
        this->dia = dia;
    }
    void setMes(int mes) {
        this->mes = mes;
    }
    void setAno(int ano) {
        this->ano = ano;
    }
    int getDia() {
        return this->dia;
    }
    int getMes() {
        return this->mes;
    }
    int getAno() {
        return this->ano;
    }
    string getData() {
        string sDia = to_string(this->dia);
        string sMes = to_string(this->mes);
        string sAno = to_string(this->ano);
       
        return sDia.insert(0, 2 - sDia.size(), '0') + "/" +
               sMes.insert(0, 2 - sMes.size(), '0') + "/" +
               sAno;
    }
   
    Data* dia_seguinte() {
        Data *d1 = new Data(this->dia, this->mes, this->ano);
        int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};;
        if (d1->ano%4 == 0) {
            diasNoMes[1] = 29;
        }
        d1->dia++;
        if (d1->dia > diasNoMes[d1->mes - 1]) {
            d1->dia = 1;
            d1->mes++;
            if(d1->mes > 12) {
                d1->mes = 1;
                d1->ano++;
            }
        }
        return d1;
    }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;
public:
    Contato(string email, string nome, string telefone, Data dtnasc) {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }
   
    // Construtor default
    Contato() {}

    // Getter e Setter para o email
    string getEmail() {
        return this->email;
    }

    void setEmail(string email) {
        this->email = email;
    }

    // Getter e Setter para o nome
    string getNome() {
        return this->nome;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    // Getter e Setter para o telefone
    string getTelefone() {
        return this->telefone;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    // Getter e Setter para a data de nascimento
    Data getDtNasc() {
        return this->dtnasc;
    }

    void setDtNasc(Data dtnasc) {
        this->dtnasc = dtnasc;
    }

    // Método para calcular a idade com base no ano de 2024
    int idade() {
        Data dataAtual(1, 1, 2024); // Ano de referência 2024
        int idade = dataAtual.getAno() - this->dtnasc.getAno();
        if (dataAtual.getMes() < this->dtnasc.getMes() ||
            (dataAtual.getMes() == this->dtnasc.getMes() && dataAtual.getDia() < this->dtnasc.getDia())) {
            idade--;
        }
        return idade;
    }
};

int main(int argc, char** argv) {
    // Definindo a localidade para que o método getData() funcione corretamente
    setlocale(LC_ALL, "Portuguese");

    // Criando 5 contatos
    Contato contatos[5] = {
        Contato("email1@example.com", "Nome1", "123456789", Data(1, 1, 2000)),
        Contato("email2@example.com", "Nome2", "987654321", Data(2, 2, 1995)),
        Contato("email3@example.com", "Nome3", "111111111", Data(3, 3, 1990)),
        Contato("email4@example.com", "Nome4", "222222222", Data(4, 4, 1985)),
        Contato("email5@example.com", "Nome5", "333333333", Data(5, 5, 1980))
    };

    // Exibindo os contatos com suas informações
    cout << "Lista de contatos:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos\n";
        cout << endl;
    }

    return 0;
}

