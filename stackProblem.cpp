#include<bits/stdc++.h>
using namespace std;

stack < pair <string,int> > pilha;

void removeAllItensOfStack() {
    while (!pilha.empty()) {
        pilha.pop();
    }
}

int main() {
    string linha, substring, tag, conteudo, msgErro = "None\n";
    int indexInicioConteudo = 0, indexFimConteudo = 0;
    while (getline(cin,linha)) {
        bool jaExibiuAlgo = false;
        substring = linha;
        while (substring != "") {
            int indexSinalMenorTagAbertura = substring.find('<');
            if (indexSinalMenorTagAbertura != string::npos) {
                int indexSinalMaiorTagAbertura = substring.find('>');
                if (indexSinalMaiorTagAbertura != string::npos) {
                    tag = substring.substr(indexSinalMenorTagAbertura + 1, indexSinalMaiorTagAbertura - indexSinalMenorTagAbertura - 1);
                    if (!pilha.empty() && "/" + pilha.top().first == tag) {
                        indexInicioConteudo = pilha.top().second;
                        if (indexFimConteudo == 0) {
                            // força a pegar o index da tag mais interna
                            // no primeiro match da tag com o topo da pilha termina o conteúdo
                            indexFimConteudo = indexSinalMenorTagAbertura;
                            conteudo = substring.substr(indexInicioConteudo, indexFimConteudo);
                        }
                        pilha.pop();
                        if (pilha.empty()) {
                            // pilha fica vazia caso tenha feito par com as tags, mesmo que internas
                            cout <<  conteudo << endl;
                            indexInicioConteudo = 0;
                            indexFimConteudo = 0;
                            jaExibiuAlgo = true;
                        }
                    } else {
                        pilha.push(make_pair(tag, indexSinalMenorTagAbertura));
                    }
                } else {
                    // caso na string não possua o sinal de maior (fechamento da tag)
                    substring = "";
                    removeAllItensOfStack();
                    break;
                }
                substring = substring.substr(indexSinalMaiorTagAbertura + 1, substring.size());
                if (substring == "") {
                    // limpa a pilha caso a substring esteja vazia 
                    removeAllItensOfStack();
                }
            } else {
                // caso na string não possua o sinal de menor (abertura da tag)
                substring = "";
                removeAllItensOfStack();
            }
        }
        if (!jaExibiuAlgo) {
            cout << msgErro;
        }
    }
    return 0;
}