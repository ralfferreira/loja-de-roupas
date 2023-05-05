//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 05 de maio de 2023

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Produto.h"
#include "Roupas.h"
#include "Calcados.h"
#include "Acessorios.h"

using namespace std;

int main() {
    vector<Produto*> produtos;
    ofstream arquivoSaida("Produtos.txt");
    int opcao;

    do {
        cout << "\t\t  ------ Olá funcionário da Viral Falx ------";
        cout << "\n\n";
        cout << "\n";
        cout << "\n \t\t\t 1. LISTAR PRODUTOS";
        cout << "\n \t\t\t 2. ADICIONAR PRODUTOS";
        cout << "\n \t\t\t 3. ATUALIZAR PRODUTOS";
        cout << "\n \t\t\t 4. APAGAR PRODUTOS";
        cout << "\n \t\t\t 5. SAIR";
        cout << "\n \t\t\t Digite sua opção: ";
        cin >> opcao;
        cin.ignore();
        cout << "\n\n";

        switch (opcao) {
            case 1:
                if (produtos.empty()) {
                    cout << "Não há produtos cadastrados." << endl;
                } else {
                    cout << "Lista de produtos:" << endl;
                    for (auto produto : produtos) {
                        cout << "Nome: " << produto->getNomeProduto() << ", Preço: R$ " << produto->getValorDoProduto() << endl;
                    }
                }
                break;
            case 2:
                int tipoProduto;
                cout << "Escolha o tipo de produto: " << endl;
                cout << "1. Roupas" << endl;
                cout << "2. Calçados" << endl;
                cout << "3. Acessórios" << endl;
                cout << "Digite sua opção: ";
                cin >> tipoProduto;
                cin.ignore();

                switch (tipoProduto) {
                    case 1:
                        {
                            string nome;
                            double preco;
                            string tamanho;
                            string cor;
                            string material;
                            string tipo;
                            cout << "Digite o nome da roupa: ";
                            getline(cin, nome);
                            cout << "Digite o preço da roupa: R$ ";
                            cin >> preco;
                            cin.ignore();
                            cout << "Digite o tamanho da roupa: ";
                            getline(cin, tamanho);
                            cout << "Digite a cor da roupa: ";
                            getline(cin, cor);
                            cout << "Digite o material da roupa: ";
                            getline(cin, material);
                            produtos.push_back(new Roupas(nome, preco, tamanho, cor, material));
                        }
                        break;
                    case 2:
                        {
                            string nome;
                            double preco;
                            int tamanhoCalcado;
                            string cor;
                            string material;
                            string tipo;
                            cout << "Digite o nome do calçado: ";
                            getline(cin, nome);
                            cout << "Digite o preço do calçado: R$ ";
                            cin >> preco;
                            cin.ignore();
                            cout << "Digite o tamanho do calçado: ";
                            cin >> tamanhoCalcado;
                            cout << "Digite a cor do calçado: ";
                            getline(cin, cor);
                            cout << "Digite o tipo de sapato: ";
                            getline(cin, tipo);
                            produtos.push_back(new Calcados(nome, preco, tamanhoCalcado, cor, tipo));
                        }
                        break;
                    case 3:
                        {
                            string nome;
                            double preco;
                            string tamanho;
                            string cor;
                            string tipo;
                            cout << "Digite o nome do acessório: ";
                            getline(cin, nome);
                            cout << "Digite o preço do acessório: R$ ";
                            cin >> preco;
                            cin.ignore();
                            cout << "Digite o tamanho do acessório: ";
                            getline(cin, tamanho);
                            cout << "Digite a cor do acessório: ";
                            getline(cin, cor);
                            cout << "Digite o tipo de acessório: ";
                            getline(cin, tipo);
                            produtos.push_back(new Acessorios(nome, preco, tamanho, cor, tipo));
                        }
                        break;
                    default:
                        cout << "Opção inválida." << endl;
                        break;
                }
                cout << "Produto adicionado com sucesso!" << endl;

            if (arquivoSaida.is_open()) {
                for (auto produto : produtos) {
                    arquivoSaida << produto->getNomeProduto() << "," << produto->getValorDoProduto() << endl;
                }
                arquivoSaida.close();
                cout << "Produtos salvos com sucesso no arquivo Produtos.txt" << endl;
            } else {
                cout << "Erro ao salvar produtos no arquivo." << endl;
            }

            break;
        case 3:
            if (produtos.empty()) {
                cout << "Não há produtos cadastrados." << endl;
            } else {
                string nomeProduto;
                cout << "Digite o nome do produto a ser atualizado: ";
                getline(cin, nomeProduto);

                bool produtoEncontrado = false;
                for (auto produto : produtos) {
                    if (produto->getNomeProduto() == nomeProduto) {
                        double novoPreco;
                        cout << "Digite o novo preço para o produto: R$ ";
                        cin >> novoPreco;
                        produto->setValorDoProduto(novoPreco);
                        cout << "Produto atualizado com sucesso!" << endl;
                        produtoEncontrado = true;
                        break;
                    }
                }

                if (!produtoEncontrado) {
                    cout << "Produto não encontrado." << endl;
                } else {
                    if (arquivoSaida.is_open()) {
                        for (auto produto : produtos) {
                            arquivoSaida << produto->getNomeProduto() << "," << produto->getValorDoProduto() << endl;
                        }
                        arquivoSaida.close();
                        cout << "Produtos salvos com sucesso no arquivo Produtos.txt" << endl;
                    } else {
                        cout << "Erro ao salvar produtos no arquivo." << endl;
                    }
                }
            }
            break;
        case 4:
            if (produtos.empty()) {
                    cout << "Não há produtos cadastrados." << endl;
                } else {
                    string nomeProduto;
                    cout << "Digite o nome do produto a ser excluído: ";
                    getline(cin, nomeProduto);

                    for (auto it = produtos.begin(); it != produtos.end(); it++) {
                    if ((*it)->getNomeProduto() == nomeProduto) {
                        produtos.erase(it);
                        cout << "Produto excluído com sucesso!" << endl;

                        if (arquivoSaida.is_open()) {
                            for (auto produto : produtos) {
                                arquivoSaida << produto->getNomeProduto() << "," << produto->getValorDoProduto() << endl;
                            }
                            arquivoSaida.close();
                            cout << "Produtos salvos com sucesso no arquivo Produtos.txt" << endl;
                        } else {
                            cout << "Erro ao salvar produtos no arquivo." << endl;
                        }
                        break;
                    }
                }
            }
            break;
        case 5:
            cout << "Saindo" << endl;
            if (arquivoSaida.is_open()) {
                for (auto produto : produtos) {
                    arquivoSaida << produto->getNomeProduto() << "," << produto->getValorDoProduto() << endl;
                }
                arquivoSaida.close();
            } else {
                cout << "Erro ao salvar produtos no arquivo." << endl;
            }
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }
} while (opcao != 5);

return 0;
}