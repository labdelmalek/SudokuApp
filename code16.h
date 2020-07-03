#ifndef CODE16_H
#define CODE16_H
#include <QMainWindow>
#include <stdio.h>
#include <iostream>
#include<math.h>
#include <QTime>
#include <time.h>
using namespace std;


class code16
{
public:


    private :
    int  **Sudoku_Solution;
    int  **Sudoku_Empty;
    int **Sudoku_reset;



public:
    int indication=9;


    int** get_grill(){
        return Sudoku_Empty;
    }
    //basic constructor

                    code16(){
srand(time(NULL));
                        int sudoku1[16][16] ;
                        int permute90[16][16] ;
                        int permute90hori[16][16] ;
                                    //reserving space in memory
                        this->Sudoku_Solution=new int*[16];
                        this->Sudoku_Empty=new int*[16];
                        this->Sudoku_reset=new int*[16];


                        for(int i=0;i<16;i++){
                            this->Sudoku_Solution[i]=new int[16];
                            this->Sudoku_Empty[i]=new int[16];
                            this->Sudoku_reset[i]=new int[16];

                                            }

                                    //filling the grills
                        sudoku1[0][0]=1;
                        sudoku1[0][1]=6;
                        sudoku1[0][2]=13;
                        sudoku1[0][3]=7;
                        sudoku1[0][4]=3;
                        sudoku1[0][5]=14;
                        sudoku1[0][6]=12;
                        sudoku1[0][7]=2;
                        sudoku1[0][8]=8;
                        sudoku1[0][9]=10;
                        sudoku1[0][10]=9;
                        sudoku1[0][11]=4;
                        sudoku1[0][12]=15;
                        sudoku1[0][13]=11;
                        sudoku1[0][14]=5;
                        sudoku1[0][15]=16;
                        sudoku1[1][0]=15;
                        sudoku1[1][1]=3;
                        sudoku1[1][2]=2;
                        sudoku1[1][3]=12;
                        sudoku1[1][4]=10;
                        sudoku1[1][5]=9;
                        sudoku1[1][6]=15;
                        sudoku1[1][7]=11;
                        sudoku1[1][8]=6;
                        sudoku1[1][9]=1;
                        sudoku1[1][10]=5;
                        sudoku1[1][11]=16;
                        sudoku1[1][12]=7;
                        sudoku1[1][13]=8;
                        sudoku1[1][14]=4;
                        sudoku1[1][15]=14;
                        sudoku1[2][0]=4;
                        sudoku1[2][1]=10;
                        sudoku1[2][2]=16;
                        sudoku1[2][3]=15;
                        sudoku1[2][4]=7;
                        sudoku1[2][5]=6;
                        sudoku1[2][6]=8;
                        sudoku1[2][7]=5;
                        sudoku1[2][8]=11;
                        sudoku1[2][9]=13;
                        sudoku1[2][10]=14;
                        sudoku1[2][11]=3;
                        sudoku1[2][12]=9;
                        sudoku1[2][13]=12;
                        sudoku1[2][14]=1;
                        sudoku1[2][15]=2;
                        sudoku1[3][0]=9;
                        sudoku1[3][1]=11;
                        sudoku1[3][2]=8;
                        sudoku1[3][3]=5;
                        sudoku1[3][4]=13;
                        sudoku1[3][5]=1;
                        sudoku1[3][6]=4;
                        sudoku1[3][7]=16;
                        sudoku1[3][8]=15;
                        sudoku1[3][9]=12;
                        sudoku1[3][10]=7;
                        sudoku1[3][11]=2;
                        sudoku1[3][12]=6;
                        sudoku1[3][13]=3;
                        sudoku1[3][14]=14;
                        sudoku1[3][15]=10;
                        sudoku1[4][0]=5;
                        sudoku1[4][1]=12;
                        sudoku1[4][2]=14;
                        sudoku1[4][3]=6;
                        sudoku1[4][4]=8;
                        sudoku1[4][5]=11;
                        sudoku1[4][6]=7;
                        sudoku1[4][7]=4;
                        sudoku1[4][8]=10;
                        sudoku1[4][9]=9;
                        sudoku1[4][10]=15;
                        sudoku1[4][11]=13;
                        sudoku1[4][12]=3;
                        sudoku1[4][13]=2;
                        sudoku1[4][14]=16;
                        sudoku1[4][15]=1;
                        sudoku1[5][0]=16;
                        sudoku1[5][1]=2;
                        sudoku1[5][2]=7;
                        sudoku1[5][3]=4;
                        sudoku1[5][4]=9;
                        sudoku1[5][5]=13;
                        sudoku1[5][6]=6;
                        sudoku1[5][7]=10;
                        sudoku1[5][8]=12;
                        sudoku1[5][9]=3;
                        sudoku1[5][10]=11;
                        sudoku1[5][11]=1;
                        sudoku1[5][12]=8;
                        sudoku1[5][13]=5;
                        sudoku1[5][14]=15;
                        sudoku1[5][15]=14;
                        sudoku1[6][0]=13;
                        sudoku1[6][1]=15;
                        sudoku1[6][2]=10;
                        sudoku1[6][3]=3;
                        sudoku1[6][4]=1;
                        sudoku1[6][5]=2;
                        sudoku1[6][6]=16;
                        sudoku1[6][7]=14;
                        sudoku1[6][8]=4;
                        sudoku1[6][9]=8;
                        sudoku1[6][10]=6;
                        sudoku1[6][11]=5;
                        sudoku1[6][12]=12;
                        sudoku1[6][13]=9;
                        sudoku1[6][14]=11;
                        sudoku1[6][15]=7;
                        sudoku1[7][0]=11;
                        sudoku1[7][1]=9;
                        sudoku1[7][2]=1;
                        sudoku1[7][3]=8;
                        sudoku1[7][4]=12;
                        sudoku1[7][5]=15;
                        sudoku1[7][6]=5;
                        sudoku1[7][7]=3;
                        sudoku1[7][8]=7;
                        sudoku1[7][9]=2;
                        sudoku1[7][10]=16;
                        sudoku1[7][11]=14;
                        sudoku1[7][12]=4;
                        sudoku1[7][13]=10;
                        sudoku1[7][14]=13;
                        sudoku1[7][15]=6;
                        sudoku1[8][0]=2;
                        sudoku1[8][1]=13;
                        sudoku1[8][2]=5;
                        sudoku1[8][3]=1;
                        sudoku1[8][4]=4;
                        sudoku1[8][5]=12;
                        sudoku1[8][6]=11;
                        sudoku1[8][7]=6;
                        sudoku1[8][8]=9;
                        sudoku1[8][9]=14;
                        sudoku1[8][10]=3;
                        sudoku1[8][11]=8;
                        sudoku1[8][12]=16;
                        sudoku1[8][13]=7;
                        sudoku1[8][14]=10;
                        sudoku1[8][15]=15;
                        sudoku1[9][0]=6;
                        sudoku1[9][1]=8;
                        sudoku1[9][2]=9;
                        sudoku1[9][3]=11;
                        sudoku1[9][4]=16;
                        sudoku1[9][5]=10;
                        sudoku1[9][6]=13;
                        sudoku1[9][7]=7;
                        sudoku1[9][8]=1;
                        sudoku1[9][9]=15;
                        sudoku1[9][10]=2;
                        sudoku1[9][11]=12;
                        sudoku1[9][12]=5;
                        sudoku1[9][13]=14;
                        sudoku1[9][14]=3;
                        sudoku1[9][15]=4;
                        sudoku1[10][0]=12;
                        sudoku1[10][1]=16;
                        sudoku1[10][2]=15;
                        sudoku1[10][3]=10;
                        sudoku1[10][4]=14;
                        sudoku1[10][5]=3;
                        sudoku1[10][6]=2;
                        sudoku1[10][7]=1;
                        sudoku1[10][8]=5;
                        sudoku1[10][9]=7;
                        sudoku1[10][10]=4;
                        sudoku1[10][11]=6;
                        sudoku1[10][12]=11;
                        sudoku1[10][13]=13;
                        sudoku1[10][14]=8;
                        sudoku1[10][15]=9;

                        sudoku1[11][0]=3;
                        sudoku1[11][1]=7;
                        sudoku1[11][2]=4;
                        sudoku1[11][3]=14;
                        sudoku1[11][4]=5;
                        sudoku1[11][5]=8;
                        sudoku1[11][6]=9;
                        sudoku1[11][7]=15;
                        sudoku1[11][8]=13;
                        sudoku1[11][9]=16;
                        sudoku1[11][10]=10;
                        sudoku1[11][11]=11;
                        sudoku1[11][12]=2;
                        sudoku1[11][13]=1;
                        sudoku1[11][14]=6;
                        sudoku1[11][15]=12;
                        sudoku1[12][0]=15;
                        sudoku1[12][1]=4;
                        sudoku1[12][2]=12;
                        sudoku1[12][3]=13;
                        sudoku1[12][4]=2;
                        sudoku1[12][5]=5;
                        sudoku1[12][6]=10;
                        sudoku1[12][7]=8;
                        sudoku1[12][8]=3;
                        sudoku1[12][9]=6;
                        sudoku1[12][10]=1;
                        sudoku1[12][11]=7;
                        sudoku1[12][12]=14;
                        sudoku1[12][13]=16;
                        sudoku1[12][14]=9;
                        sudoku1[12][15]=11;

                        sudoku1[13][0]=10;
                        sudoku1[13][1]=14;
                        sudoku1[13][2]=3;
                        sudoku1[13][3]=2;
                        sudoku1[13][4]=6;
                        sudoku1[13][5]=4;
                        sudoku1[13][6]=1;
                        sudoku1[13][7]=12;
                        sudoku1[13][8]=16;
                        sudoku1[13][9]=11;
                        sudoku1[13][10]=8;
                        sudoku1[13][11]=9;
                        sudoku1[13][12]=13;
                        sudoku1[13][13]=15;
                        sudoku1[13][14]=7;
                        sudoku1[13][15]=5;

                        sudoku1[14][0]=7;
                        sudoku1[14][1]=5;
                        sudoku1[14][2]=11;
                        sudoku1[14][3]=9;
                        sudoku1[14][4]=15;
                        sudoku1[14][5]=16;
                        sudoku1[14][6]=3;
                        sudoku1[14][7]=13;
                        sudoku1[14][8]=14;
                        sudoku1[14][9]=4;
                        sudoku1[14][10]=12;
                        sudoku1[14][11]=10;
                        sudoku1[14][12]=1;
                        sudoku1[14][13]=6;
                        sudoku1[14][14]=2;
                        sudoku1[14][15]=8;

                        sudoku1[15][0]=8;
                        sudoku1[15][1]=1;
                        sudoku1[15][2]=6;
                        sudoku1[15][3]=16;
                        sudoku1[15][4]=11;
                        sudoku1[15][5]=7;
                        sudoku1[15][6]=14;
                        sudoku1[15][7]=9;
                        sudoku1[15][8]=2;
                        sudoku1[15][9]=5;
                        sudoku1[15][10]=13;
                        sudoku1[15][11]=15;
                        sudoku1[15][12]=10;
                        sudoku1[15][13]=4;
                        sudoku1[15][14]=12;
                        sudoku1[15][15]=3;


                            // permuting algorithm 90 degree
                        for(int i=0;i<=15;i++){
                            for(int j=0;j<=15;j++){
                                permute90[i][j]=sudoku1[j][15-i];
                            }
                        }
                        int x=0,y=0;


                        for(int  i=0;i<16;i++){
                            for (int j=0;j<16;j++){
                                if (permute90[i][j] == x){
                                    permute90[i][j]=y;}

                                else if(permute90[i][j]==y){
                                    permute90[i][j]=x;

                                }
                            } }

                                               // horizontal permutation
                        for(int i=0;i<=15;i++){
                            for(int j=0;j<=15;j++){
                                permute90hori[i][j]=permute90[15-i][j];
                            }
                        }

                        // copying the last values to the solution matrix and the empty one
                        for(int  i=0;i<16;i++){
                            for (int j=0;j<16;j++){
                                this->Sudoku_Empty[i][j]=permute90hori[i][j];
                                this->Sudoku_Solution[i][j]=permute90hori[i][j];


                            }}

                        // permuting two numbers randomly
                        x=1+rand()%16;
                        y=1+rand()%16;
                        while(x==y){

                            y=1+rand()%16;

                        }
                        for(int  i=0;i<16;i++){
                            for (int j=0;j<16;j++){
                                if (Sudoku_Empty[i][j] == x){
                                    Sudoku_Empty[i][j]=y;
                                    Sudoku_Solution[i][j]=y;

                                }

                                else if(Sudoku_Empty[i][j]==y){
                                    Sudoku_Empty[i][j]=x;
                                    Sudoku_Solution[i][j]=x;
                                }
                            } }
                        // permuting two numbers randomly

                        x=1+rand()%16;
                        y=1+rand()%16;
                        while(x==y){

                            y=1+rand()%16;

                        }
                        for(int  i=0;i<16;i++){
                            for (int j=0;j<16;j++){
                                if (Sudoku_Empty[i][j] == x){
                                    Sudoku_Empty[i][j]=y;
                                    Sudoku_Solution[i][j]=y;

                                }

                                else if(Sudoku_Empty[i][j]==y){
                                    Sudoku_Empty[i][j]=x;
                                    Sudoku_Solution[i][j]=x;
                                }
                            } }

 // permuting two numbers randomly

                        x=1+rand()%16;
                        y=1+rand()%16;
                        while(x==y){

                            y=1+rand()%16;

                        }
                        for(int  i=0;i<16;i++){
                            for (int j=0;j<16;j++){
                                if (Sudoku_Empty[i][j] == x){
                                    Sudoku_Empty[i][j]=y;
                                    Sudoku_Solution[i][j]=y;

                                }

                                else if(Sudoku_Empty[i][j]==y){
                                    Sudoku_Empty[i][j]=x;
                                    Sudoku_Solution[i][j]=x;
                                }
                            } }



                  }
                    // write an element in the gameplay matrix
                       void element_write(int abs, int ord, int number){

                           this->Sudoku_Empty[abs][ord]=number;
                       }
                    // write an element in the backup matrix
                    void element_write_backup(int abs, int ord, int number){

                        this->Sudoku_reset[abs][ord]=number;
                    }
                    // write an element in the solution matrix
                    void element_write_solution(int abs, int ord, int number){

                        this->Sudoku_Solution[abs][ord]=number;
                    }
                    // recover an element from the matrix knowing its position
                    int element_read(int abs, int ord){
                        return this->Sudoku_Empty[abs][ord];
                    }
                    // recover an element from the backup matrix knowing its position
                    int element_read_backup(int abs, int ord){
                        return this->Sudoku_reset[abs][ord];
                    }
                    // recover an element from the matrix solution knowing its position
                    int element_read_solution1(int abs, int ord){
                        return this->Sudoku_Solution[abs][ord];
                    }

    //Clearing the grill
                    void clear_grille(){

                        int a ;
                        int b;
                        int i=0;
                        int x;

                        x=rand()%3;
                        while(i<(7+x)){
                            a=rand() % 4;
                            b=rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=4+rand() % 4;
                            b=rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=8+rand() % 4;
                            b=rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=12+rand() % 4;
                            b=rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=rand() % 4;
                            b=4+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=4+rand() % 4;
                            b=4+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=8+rand() % 4;
                            b=4+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=12+rand() % 4;
                            b=4+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=rand() % 4;
                            b=8+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=4+rand() % 4;
                            b=8+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=8+rand() % 4;
                            b=8+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=12+rand() % 4;
                            b=8+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }

                        x=rand()%3;
                        i=0;
                        while(i<(7+x)){
                            a=rand() % 4;
                            b=12+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=4+rand() % 4;
                            b=12+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=8+rand() % 4;
                            b=12+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(7+x)){
                            a=12+rand() % 4;
                            b=12+rand() % 4;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }




                        for(int i=0;i<16;i++){
                            for(int j=0;j<16;j++){
                                Sudoku_reset[i][j]=Sudoku_Empty[i][j];

                            }
                        }
                                                }

                    //reset the empty grill
                    void reset_grille(){
                        for(int i=0;i<16;i++){
                            for(int j=0; j<16; j++){
                                Sudoku_Empty[i][j]=Sudoku_reset[i][j];            }
                        }

                    }
    //indication fuctions, the user has only 5 indications means this function can be called only if the variable indication is >0//
         /*           int* indication_sudoku(){
                        int tab[2];
                        if(this->indication>0){
                            indication--;
                        int i;
                        int j;
                        do{
                            i=rand() % 9;
                            j=rand() % 9;        }
                        while(this->Sudoku_Empty[i][j]!=0);
                            this->Sudoku_Empty[i][j]=this->Sudoku_Solution[i][j];
                        tab[0]=i;
                        tab[1]=j;}
                    return tab;
                    } */
    // checking function, if the user enables it  this function needs to run each time he enters a value to an empty case//
    // this is a boolean funtion that returns either 1 if the value entered is wrong and 0 if it's right

                    bool goodcolumn (int nombre,int abs, int ord){ // pour tester si la valeur existe sur la colonne
                        int indicateur=1; //indicateur d'existance du chiffre sur la colonne
                        for(int i=0;i<16;i++){
                            if(this->Sudoku_Empty[i][ord]==nombre && i!=abs){
                                indicateur=0;
                                i=16;
                            }
                        }
                        return indicateur;
                    }

                    bool goodrow (int nombre,int abs, int ord){ // pour tester si la valeur existe sur la ligne
                        int indicateur=1;//indicateur d'existance du chiffre sur la colonne
                        for(int i=0;i<16;i++){
                            if(this->Sudoku_Empty[abs][i]==nombre && i!=ord)  {
                                indicateur=0;
                                i=99;
                            }
                        }
                        return indicateur;
                    }
                            // comparaison de la valeur entree avec la solution
    bool goodblock(int nombre,int abs, int ord){// pour tester si la valeur existe sur le block
        int indicateur=1;//indicateur d'existance du chiffre sur le block
        int nb=0;
        if(abs<=3){

            if(ord<=3){
                for(int i=0;i<=3;i++){
                    for(int j=0;j<=3;j++){
                        if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}

            }
            else {if(ord<=7){
                for(int i=0;i<=3;i++){
                    for(int j=4;j<8;j++){
                        if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}}
                else {if(ord<=11){
                    for(int i=0;i<=3;i++){
                        for(int j=8;j<12;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb+1;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}

            }
                    else{for(int i=0;i<=3;i++){
                            for(int j=12;j<16;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}}}}}


         else {if (abs<=7){

                if(ord<=3){
                    for(int i=4;i<=7;i++){
                        for(int j=0;j<4;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}

                }
                else {if(ord<=7){
                    for(int i=4;i<=7;i++){
                        for(int j=4;j<8;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}}
                    else {if(ord<=11){
                        for(int i=4;i<=7;i++){
                            for(int j=8;j<12;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}

                }
                        else{for(int i=4;i<=7;i++){
                                for(int j=12;j<16;j++){
                                    if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                        nb=nb++;
                                        if(nb>=2){
                                            indicateur=0;
                                            i=99;
                                            j=99;
                                        }}}}}}}}
        else {if (abs<=11){

                    if(ord<=3){
                        for(int i=8;i<=11;i++){
                            for(int j=0;j<4;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}

                    }
                    else {if(ord<=7){
                        for(int i=8;i<=11;i++){
                            for(int j=4;j<8;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}}
                        else {if(ord<=11){
                            for(int i=8;i<=11;i++){
                                for(int j=8;j<12;j++){
                                    if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                        nb=nb++;
                                        if(nb>=2){
                                            indicateur=0;
                                            i=99;
                                            j=99;
                                        }}}}

                    }
                            else{for(int i=8;i<=11;i++){
                                    for(int j=12;j<16;j++){
                                        if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                            nb=nb++;
                                            if(nb>=2){
                                                indicateur=0;
                                                i=99;
                                                j=99;
                                            }}}}}}}}

                else {

                  if(ord<=3){
                    for(int i=12;i<=15;i++){
                        for(int j=0;j<=3;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}

                }
                else {if(ord<=7){
                    for(int i=12;i<=15;i++){
                        for(int j=4;j<8;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}}
                    else {if(ord<=11){
                        for(int i=12;i<=15;i++){
                            for(int j=8;j<12;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}

                }
                        else{for(int i=12;i<=15;i++){
                                for(int j=12;j<16;j++){
                                    if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                        nb=nb++;
                                        if(nb>=2){
                                            indicateur=0;
                                            i=99;
                                            j=99;
                                        }}}}}}}}
                return indicateur;
    }}}
    ~code16(){
        for(int i=0;i<16;i++){
           delete Sudoku_Empty[i];
            delete Sudoku_Solution[i];
                            }
        delete Sudoku_Empty;
        delete Sudoku_Solution;
    }



};

#endif // CODE16_H
