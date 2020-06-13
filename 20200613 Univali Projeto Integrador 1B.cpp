/**
    Estrutura inicial para o jogo
    Desenvolvedor alfa Thiago Felski Pereira
    Desenvolvedor final: Acad�mico Alexandre Gon�alves da Rocha
    Data inicial: 2020-05-09
    �ltima atualiza��o: 2020-06-13
*/
#include<iostream> ///cin, cout
#include<windows.h> ///apagar o cursor, movimentar o local de escrita
#include<conio.h>   ///getch() usada pra pegar o valor digitado sem o ENTER
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <termmgr.h>

#define L 40   ///LINHAS
#define C 40   ///COLUNAS

using namespace std;

/**
    - Implementar testes para impedir que o personagem (@) entre nas paredes.
    - o teste para direita j� foi feito como exemplo (linha 82)
    -
*/


int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    short int CX=0, CY=0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.


    //Posi��o inicial do personagem no console
    int x, y;
    x=4;
    y=4;

    int cx, cy;
    cx=6;
    cy=7;
    //Vari�vel para tecla precionada
    char tecla;
    //Coordenadas para impress�o na tela
    int i,j;
    while(1)
    {

        ///Imprime o jogo: mapa e personagem.
        i=0;
        while (i<L)
        {
            j=0;
            while (j<C)
            {
                if (i==x and j==y)
                {
                    cout<<char(207); ///personagem no mapa
                }
                else if (i==cx and j==cy)
                {
                    cout<<char(254); ///caixa no mapa
                }
                else if (i==0 or i==L-1 or j==0 or j==C-1)
                {
                    cout<<char(219);//"�"; ///parede do mapa
                }
                else
                {
                    cout<<char(32); ///espa�o vazio no mapa
                }
                j++;
            }
            cout<<"\n";
            i++;
        }
        ///leitura dos comandos de movimenta��o
        tecla = getch();

        switch (tecla) {
        case ('w'):
            if (x-1==cx and cx==1 and x==2 and y==cy)
                {
                break;
            }
            else if (x-1==cx and y==cy and cx>1 and x>2)
            {
                cx=cx-1;
                x=x-1;
            }
            else if (x>1)
            {
                x=x-1;
            }
            break;
        case ('z'):
            if (x+1==cx and cx==L-2 and x==L-3 and y==cy)
            {
                break;
            }
            else if (x+1 == cx and y==cy and cx<L-2)
            {
                cx=cx+1;
                x=x+1;
            }
            else if (x+1<L-1)
            {
                x=x+1;
            }
            break;
        case ('a'):
            if ((y-1>0) and (y-1==cy) and (cy>1) and x==cx)
            {
                cy=cy-1;
                y=y-1;
            }
            else if (cy==1 and y==2 and x==cx)
                {break;}
            else if (y>1)
                {
                    y--;
                    }
            break;
        case ('d'):
            if (cy==C-2 and y==C-3 and cx==x)
            {
                break;
            }
            else if ((y-1<C-1) and (y+1==cy) and (cy<C-2) and x==cx)
            {
                cy++;
                y++;
            }
            else if (y<C-2)
            {
                y=y+1;
            }
            break;
        case 27:
            cout <<'\a' << "Aperte ESC novamente para sair ou qualquer tecla para continuar." ;

            char exitorreturn;
            exitorreturn = getch();

            switch (exitorreturn)
            {
                case 27:
                    cout << "Encerrando..." << '\a';
                    Sleep(1000);
                    cout << string(100, '\n');
                    exit(1);
                default:
                    Sleep(20);

        }
        }

        /*
            Recoloca o mapa no inicio da tela,
            isso faz com que o jogo seja escrito sempre no mesmo lugar.
            se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
        */
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // final do while da linha 49
}
