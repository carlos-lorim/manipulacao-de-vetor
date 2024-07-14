/*
 autor: Carlos Augusto Regis Lorim 
 2024.1.08.004 
 
             -- Trabalho de AEDs 1 --
 Esse sistema tem por funcao realizar acoes especificas em vetores 
 */






#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    int opcao;
    int vetor[1000];
    int tamanho = 1000;
    int valor;
    int contador;
    int numeroParaExcluir;
    int novot = 0;
    int fim;
    int i, j, n = 0;
    int vetorau[1000];
    int saida [1000];

    //gera numeros aleatorios 
    srand(time(NULL));
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = rand() % (200 - 100 + 1) + 100;
    }

    do {
        cout << "Escolha uma opção:\n";
        cout << "1. Verificar se um valor existe no vetor e mostrar sua posição\n";
        cout << "2. Contar quantas vezes um valor aparece no vetor e mostrar suas posições\n";
        cout << "3. Contar quantas vezes os valores de um intervalo aparecem no vetor\n";
        cout << "4. Inverter os valores de um vetor\n";
        cout << "5. Remover do vetor todas as ocorrências de um valor\n";
        cout << "6. Remover de um vetor todos os valores repetidos\n";
        cout << "0. Sair\n";
        cin >> opcao;


        switch (opcao) {

            case 0:
                // para a repeticao
                cout << "Saindo do programa...\n";
                break;

            case 1:

                cout << "Digite o valor que deseja verificar: ";
                cin >> valor;

                for (int i = 0; i < 1000; ++i) {
                    if (vetor[i] == valor) {
                        cout << "O valor " << valor << " foi encontrado na posição " << i << " do vetor.\n\n";
                    } else
                        cout << "Se nenhuma posição foi impressa acima, o valor " << valor << " não foi encontrado no vetor.\n\n";
                }

                break;


            case 2:
                cout << "Digite o valor que deseja contar: ";
                cin >> valor;
                contador = 0;

                for (int i = 0; i < 1000; ++i) {
                    if (vetor[i] == valor) {
                        ++contador;
                    }
                }
                cout << "O valor " << valor << " aparece " << contador << " vezes no vetor.\n";

                cout << "Posições onde o valor " << valor << " aparece:\n";
                for (int i = 0; i < 1000; ++i) {
                    if (vetor[i] == valor) {
                        cout << i << " ";
                    }
                }
                cout << "\n\n"; // Adicionando uma quebra de linha
                break;


            case 3:
                cout << "Digite o valor inicial do intervalo: ";
                cin >> valor;
                cout << "Digite o valor final do intervalo: ";
                cin >> fim;
                contador = 0;

                for (int i = 0; i < 1000; ++i) {
                    if (vetor[i] >= valor && vetor[i] <= fim) {
                        ++contador;
                    }
                }
                cout << "Quantidade de valores entre " << valor << " e " << fim << ": " << contador << "\n";
                break;



            case 4:
                for (int a = 0; a < 1000; ++a) {
                    vetorau[a] = vetor[999 - a];
                }
                for (int i = 0; i < 1000; ++i) {
                    cout << vetorau[i] << " ";
                }
                cout << "\n\n"; // Adicionando uma quebra de linha
                break;

            case 5:
                cout << "Digite o valor que deseja excluir: ";
                cin >> numeroParaExcluir;

                novot = 0; // Reinicializa novot para 0
                if (vetor[i] == numeroParaExcluir) {
                    // Copia os elementos diferentes de numeroParaExcluir para um novo vetor
                    for (int i = 0; i < tamanho; ++i) {
                        if (vetor[i] != numeroParaExcluir) {
                            vetor[novot++] = vetor[i];
                             cout << "Elementos removidos com sucesso!\n\n";
                break;

                        }
                    }
                }else cout<< "esse valor nao esta no vetor \n\n ";
                   

                // Atualiza o tamanho do vetor original para o novo tamanho
                tamanho = novot;

                break;

            case 6:
                /* Remove elementos com valor duplicado */
                for (i = 0; i < 1000; i++) {
                    for (j = 0; j < n; j++) {
                        if (vetor[i] == saida[j])
                            break;
                    }
                    if (j == n) {
                        saida[n] = vetor[i];
                        n++;
                    }
                }

                // Exibe Vetor de Saida 
                cout << "Depois: ";
                for (i = 0; i < n; i++)
                    cout << saida[i] << " "; // Adicionando um espaço entre os elementos
                cout << "\n\n"; // Adicionando uma quebra de linha
                break;

            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida.\n";
                break;
        }
    } while (opcao != 0); // Condição para continuar o loop

    return 0;
}