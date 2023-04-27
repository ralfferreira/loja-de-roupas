//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 05 de maio de 2023

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Produto{
  protected:
    int ID;
    string nomeProduto;
    double valorDoProduto;

  public:
    Produto();
    Produto(int ID, string nomeProduto, double valorDoProduto);
    int getID();
    string getNomeProduto();
    double getValorDoProduto();
    void setID(int ID);
    void setNomeProduto(string nomeProduto);
    void setValorDoProduto(double valorDoProduto);
    virtual void MostrarNaTela();
};