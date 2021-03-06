/**
    Estrutura inicial para o jogo
    Desenvolvedor alfa Thiago Felski Pereira
    Desenvolvedor final: Acad�mico Alexandre Gon�alves da Rocha
    Data inicial: 2020-05-09
    �ltima atualiza��o: 2020-06-13
*/

#include <iostream> ///cin, cout
#include <windows.h> ///apagar o cursor, movimentar o local de escrita
#include <conio.h>   ///getch() usada pra pegar o valor digitado sem o ENTER.
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <termmgr.h>
#include <ctype.h> //necess�rio para lidar com mai�sculas e min�sculas

#define L 40 //linhas
#define C 40 //colunas

using namespace std;

int main()
{
SetConsoleTitle ("Univali - Projeto Integrador 1B 2020/1 - Grupo 4");

    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA

    //https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt

    //recupera refer�ncia para que a aplica��o possa dar sa�da pelo console
    //https://docs.microsoft.com/en-us/windows/console/getstdhandle
    //depende de windows.h. Achar solu��o equivalente para Linux
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    //cont�m informa��o sobre tamanho e visibilidade do cursor
    //https://docs.microsoft.com/en-us/windows/console/console-cursor-info-str
    //depende de windows.h. Achar solu��o para Linux
    CONSOLE_CURSOR_INFO     cursorInfo;

    //recupera infoma��o sobre tamanho e visibilidade do cursor
    //depende de windows.h.
    GetConsoleCursorInfo(out, &cursorInfo);

    //reduz o tamanho do cursor ao m�nimo
    cursorInfo.dwSize = 1;

    //torna o cursor invis�vel
    cursorInfo.bVisible = 0;

    //atribui os valores de tamanho e
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA

    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    short CX=0, CY=0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA




    //Inicializa o her�i no console
    int x, y;
    x=4;
    y=4;

    //Inicializa a caixa no console

    int cx, cy;
    cx=6;
    cy=7;

    //Vari�vel para tecla pressionada
    char tecla;

    //Coordenadas para impress�o na tela
    //Aten��o: coordenadas iniciais = {0,0}
    int i,j;

    //define tamanho e posi��o da janela
    //https://www.daniweb.com/programming/software-development/threads/308396/setting-the-console-window-size

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1024, 768, TRUE);


    //in�cio do loop de sa�da
    while(1)
    {
        //Imprime o jogo: mapa e personagem.
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
                    cout<<char(219); ///parede do mapa
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

        tecla = getch(); //captura movimenta��o pelo teclado SEM PRECISAR ESPERAR ENTER. Depende de conio.h. N�o-standard.
        tecla = tolower(tecla); //corrige qualquer problema decorrente de CAPSLOCK = 1.

        //estabelece o comportamento em caso das teclas W, A, D ou Z serem pressionadas
        //
        switch (tecla)
        {
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
            cout <<'\a' << "Aperte ESC novamente para sair ou qualquer tecla para continuar.\n" ;

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
        cursorInfo.bVisible = 0;
        cursorInfo.dwSize = 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // final do while da linha 49
}
