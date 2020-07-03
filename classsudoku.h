#ifndef CLASSSUDOKU_H
#define CLASSSUDOKU_H
#include <stdio.h>
#include <iostream>
#include<math.h>
#include <QTime>
#include <time.h>
using namespace std;

class sudoku{
    private :
    int  **Sudoku_Solution;
    int  **Sudoku_Empty;
    int **Sudoku_reset;

     // the variable level takes 0 for easy , 1 for medium and 2 for exprert// all 9x9

public:
    int indication=5;
    int** get_grill(){
        return Sudoku_Empty;
    }
    //basic constructor

                    sudoku (){
srand(time(NULL));
                        int sudoku1[9][9] ;
                        int permute90[9][9] ;
                        int permute90hori[9][9] ;
                                    //reserving space in memory
                        this->Sudoku_Solution=new int*[9];
                        this->Sudoku_Empty=new int*[9];
                        this->Sudoku_reset=new int*[9];


                        for(int i=0;i<9;i++){
                            this->Sudoku_Solution[i]=new int[9];
                            this->Sudoku_Empty[i]=new int[9];
                            this->Sudoku_reset[i]=new int[9];

                                            }

                                    //filling the grills
                        sudoku1[0][0]=6;
                        sudoku1[0][1]=1;
                        sudoku1[0][2]=4;
                        sudoku1[0][3]=9;
                        sudoku1[0][4]=2;
                        sudoku1[0][5]=5;
                        sudoku1[0][6]=3;
                        sudoku1[0][7]=7;
                        sudoku1[0][8]=8;
                        sudoku1[1][0]=3;
                        sudoku1[1][1]=2;
                        sudoku1[1][2]=5;
                        sudoku1[1][3]=8;
                        sudoku1[1][4]=1;
                        sudoku1[1][5]=7;
                        sudoku1[1][6]=4;
                        sudoku1[1][7]=6;
                        sudoku1[1][8]=9;
                        sudoku1[2][0]=7;
                        sudoku1[2][1]=8;
                        sudoku1[2][2]=9;
                        sudoku1[2][3]=6;
                        sudoku1[2][4]=3;
                        sudoku1[2][5]=4;
                        sudoku1[2][6]=5;
                        sudoku1[2][7]=2;
                        sudoku1[2][8]=1;
                        sudoku1[3][0]=1;
                        sudoku1[3][1]=5;
                        sudoku1[3][2]=2;
                        sudoku1[3][3]=7;
                        sudoku1[3][4]=4;
                        sudoku1[3][5]=3;
                        sudoku1[3][6]=8;
                        sudoku1[3][7]=9;
                        sudoku1[3][8]=6;
                        sudoku1[4][0]=8;
                        sudoku1[4][1]=6;
                        sudoku1[4][2]=3;
                        sudoku1[4][3]=1;
                        sudoku1[4][4]=9;
                        sudoku1[4][5]=2;
                        sudoku1[4][6]=7;
                        sudoku1[4][7]=4;
                        sudoku1[4][8]=5;
                        sudoku1[5][0]=9;
                        sudoku1[5][1]=4;
                        sudoku1[5][2]=7;
                        sudoku1[5][3]=5;
                        sudoku1[5][4]=8;
                        sudoku1[5][5]=6;
                        sudoku1[5][6]=1;
                        sudoku1[5][7]=3;
                        sudoku1[5][8]=2;
                        sudoku1[6][0]=4;
                        sudoku1[6][1]=9;
                        sudoku1[6][2]=1;
                        sudoku1[6][3]=2;
                        sudoku1[6][4]=7;
                        sudoku1[6][5]=8;
                        sudoku1[6][6]=6;
                        sudoku1[6][7]=5;
                        sudoku1[6][8]=3;
                        sudoku1[7][0]=2;
                        sudoku1[7][1]=3;
                        sudoku1[7][2]=6;
                        sudoku1[7][3]=4;
                        sudoku1[7][4]=5;
                        sudoku1[7][5]=1;
                        sudoku1[7][6]=9;
                        sudoku1[7][7]=8;
                        sudoku1[7][8]=7;
                        sudoku1[8][0]=5;
                        sudoku1[8][1]=7;
                        sudoku1[8][2]=8;
                        sudoku1[8][3]=3;
                        sudoku1[8][4]=6;
                        sudoku1[8][5]=9;
                        sudoku1[8][6]=2;
                        sudoku1[8][7]=1;
                        sudoku1[8][8]=4;

                            // permuting algorithm 90 degree
                        for(int i=0;i<=8;i++){
                            for(int j=0;j<=8;j++){
                                permute90[i][j]=sudoku1[j][8-i];
                            }
                        }
                        int x=0,y=0;


                        for(int  i=0;i<9;i++){
                            for (int j=0;j<9;j++){
                                if (permute90[i][j] == x){
                                    permute90[i][j]=y;}

                                else if(permute90[i][j]==y){
                                    permute90[i][j]=x;

                                }
                            } }

                                               // horizontal permutation
                        for(int i=0;i<=8;i++){
                            for(int j=0;j<=8;j++){
                                permute90hori[i][j]=permute90[8-i][j];
                            }
                        }

                        // copying the last values to the solution matrix and the empty one
                        for(int  i=0;i<9;i++){
                            for (int j=0;j<9;j++){
                                this->Sudoku_Empty[i][j]=permute90hori[i][j];
                                this->Sudoku_Solution[i][j]=permute90hori[i][j];


                            }}

                        // permuting two numbers randomly
                        x=1+rand()%9;
                        y=1+rand()%9;
                        while(x==y){

                            y=1+rand()%9;

                        }
                        for(int  i=0;i<9;i++){
                            for (int j=0;j<9;j++){
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

                        x=1+rand()%9;
                        y=1+rand()%9;
                        while(x==y){

                            y=1+rand()%9;

                        }
                        for(int  i=0;i<9;i++){
                            for (int j=0;j<9;j++){
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

                        x=1+rand()%9;
                        y=1+rand()%9;
                        while(x==y){

                            y=1+rand()%9;

                        }
                        for(int  i=0;i<9;i++){
                            for (int j=0;j<9;j++){
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
                    void clear_grille(int level){

                                            int a ;
                                            int b;
                                            int k;
                                            int i=0;
                                            int x;
                                            if(level==0)k=36;
                                            else if(level==1)k=45;
                                            else k=54;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=rand() % 3;
                                                b=rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=3+rand() % 3;
                                                b=rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=6+rand() % 3;
                                                b=rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=rand() % 3;
                                                b=3+rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=3+rand() % 3;
                                                b=3+rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=6+rand() % 3;
                                                b=3+rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=rand() % 3;
                                                b=6+rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                           while(i<(((k/9)-1)+x)){
                                                a=3+rand() % 3;
                                                b=6+rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }
                                            i=0;
                                            x=rand()%3;
                                            while(i<(((k/9)-1)+x)){
                                                a=6+rand() % 3;
                                                b=6+rand() % 3;
                                                if(this->Sudoku_Empty[a][b]!=0){
                                                    i=i+1;
                                                    this->Sudoku_Empty[a][b]=0;}

                                                        }

                                            for(int i=0;i<9;i++){
                                                for(int j=0;j<9;j++){
                                                    Sudoku_reset[i][j]=Sudoku_Empty[i][j];

                                                }
                                            }
                                                                    }
                    //reset the empty grill
                    void reset_grille(){
                        for(int i=0;i<9;i++){
                            for(int j=0; j<9; j++){
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
                        for(int i=0;i<9;i++){
                            if(this->Sudoku_Empty[i][ord]==nombre && i!=abs){
                                indicateur=0;
                                i=9;
                            }
                        }
                        return indicateur;
                    }

                    bool goodrow (int nombre,int abs, int ord){ // pour tester si la valeur existe sur la ligne
                        int indicateur=1;//indicateur d'existance du chiffre sur la colonne
                        for(int i=0;i<9;i++){
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
        if(abs<=2){

            if(ord<=2){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if (nombre==this->Sudoku_Empty[j][i]) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}

            }
            else if(ord<=5){
                for(int i=3;i<6;i++){
                    for(int j=0;j<3;j++){
                        if (nombre==this->Sudoku_Empty[j][i]) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}
            }
            else{
                    for(int i=6;i<9;i++){
                        for(int j=0;j<3;j++){
                            if (nombre==this->Sudoku_Empty[j][i]) {
                                nb=nb+1;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}
                }
            }
         else if (abs<=5){

            if(ord<=2){
                for(int i=0;i<3;i++){
                    for(int j=3;j<6;j++){
                        if (nombre==this->Sudoku_Empty[j][i]) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}

            }
            else if(ord<=5){
                for(int i=3;i<6;i++){
                    for(int j=3;j<6;j++){
                        if (nombre==this->Sudoku_Empty[j][i]) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}
            }
            else{
                for(int i=6;i<9;i++){
                    for(int j=3;j<6;j++){
                        if (nombre==this->Sudoku_Empty[j][i] ) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}
            }
        }
        else {
            if(ord<=2){
                for(int i=0;i<3;i++){
                    for(int j=6;j<9;j++){
                        if (nombre==this->Sudoku_Empty[j][i]) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}

            }
            else if(ord<=5){
                for(int i=3;i<6;i++){
                    for(int j=6;j<9;j++){
                        if (nombre==this->Sudoku_Empty[j][i] ) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}

            }
            else{

                for(int i=6;i<9;i++){
                    for(int j=6;j<9;j++){
                        if (nombre==this->Sudoku_Empty[j][i] ) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}
            }
        }
                return indicateur;
    }
    ~sudoku(){
        for(int i=0;i<9;i++){
           delete Sudoku_Empty[i];
            delete Sudoku_Solution[i];
                            }
        delete Sudoku_Empty;
        delete Sudoku_Solution;
    }


};
#endif // CLASSSUDOKU_H
