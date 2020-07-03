#ifndef SUDOKU12_H
#define SUDOKU12_H

#include <QMainWindow>


#include <stdio.h>
#include <iostream>
#include<math.h>
#include <QTime>
#include <time.h>
using namespace std;

class sudoku12{
    private :
    int  **Sudoku_Solution;
    int  **Sudoku_Empty;
    int **Sudoku_reset;



public:
    int indication=8;


    int** get_grill(){
        return Sudoku_Empty;
    }
    //basic constructor

                    sudoku12(){
srand(time(NULL));
                        int sudoku1[12][12] ;
                         int sudoku1hori[12][12] ;
                                    //reserving space in memory
                        this->Sudoku_Solution=new int*[12];
                        this->Sudoku_Empty=new int*[12];
                        this->Sudoku_reset=new int*[12];


                        for(int i=0;i<12;i++){
                            this->Sudoku_Solution[i]=new int[12];
                            this->Sudoku_Empty[i]=new int[12];
                            this->Sudoku_reset[i]=new int[12];

                                            }

                                    //filling the grills
                        sudoku1[0][0]=10;
                        sudoku1[0][1]=2;
                        sudoku1[0][2]=4;
                        sudoku1[0][3]=9;
                        sudoku1[0][4]=6;
                        sudoku1[0][5]=5;
                        sudoku1[0][6]=7;
                        sudoku1[0][7]=3;
                        sudoku1[0][8]=11;
                        sudoku1[0][9]=1;
                        sudoku1[0][10]=8;
                        sudoku1[0][11]=12;
                        sudoku1[1][0]=6;
                        sudoku1[1][1]=12;
                        sudoku1[1][2]=11;
                        sudoku1[1][3]=5;
                        sudoku1[1][4]=10;
                        sudoku1[1][5]=2;
                        sudoku1[1][6]=1;
                        sudoku1[1][7]=8;
                        sudoku1[1][8]=7;
                        sudoku1[1][9]=9;
                        sudoku1[1][10]=4;
                        sudoku1[1][11]=3;
                        sudoku1[2][0]=3;
                        sudoku1[2][1]=1;
                        sudoku1[2][2]=7;
                        sudoku1[2][3]=8;
                        sudoku1[2][4]=4;
                        sudoku1[2][5]=11;
                        sudoku1[2][6]=9;
                        sudoku1[2][7]=12;
                        sudoku1[2][8]=5;
                        sudoku1[2][9]=10;
                        sudoku1[2][10]=6;
                        sudoku1[2][11]=2;
                        sudoku1[3][0]=5;
                        sudoku1[3][1]=3;
                        sudoku1[3][2]=2;
                        sudoku1[3][3]=7;
                        sudoku1[3][4]=9;
                        sudoku1[3][5]=10;
                        sudoku1[3][6]=11;
                        sudoku1[3][7]=4;
                        sudoku1[3][8]=8;
                        sudoku1[3][9]=12;
                        sudoku1[3][10]=1;
                        sudoku1[3][11]=6;
                        sudoku1[4][0]=4;
                        sudoku1[4][1]=8;
                        sudoku1[4][2]=6;
                        sudoku1[4][3]=11;
                        sudoku1[4][4]=2;
                        sudoku1[4][5]=12;
                        sudoku1[4][6]=5;
                        sudoku1[4][7]=1;
                        sudoku1[4][8]=9;
                        sudoku1[4][9]=3;
                        sudoku1[4][10]=7;
                        sudoku1[4][11]=10;
                        sudoku1[5][0]=9;
                        sudoku1[5][1]=10;
                        sudoku1[5][2]=12;
                        sudoku1[5][3]=1;
                        sudoku1[5][4]=3;
                        sudoku1[5][5]=8;
                        sudoku1[5][6]=6;
                        sudoku1[5][7]=7;
                        sudoku1[5][8]=2;
                        sudoku1[5][9]=5;
                        sudoku1[5][10]=11;
                        sudoku1[5][11]=4;
                        sudoku1[6][0]=7;
                        sudoku1[6][1]=9;
                        sudoku1[6][2]=5;
                        sudoku1[6][3]=2;
                        sudoku1[6][4]=8;
                        sudoku1[6][5]=6;
                        sudoku1[6][6]=12;
                        sudoku1[6][7]=10;
                        sudoku1[6][8]=4;
                        sudoku1[6][9]=11;
                        sudoku1[6][10]=3;
                        sudoku1[6][11]=1;
                        sudoku1[7][0]=1;
                        sudoku1[7][1]=4;
                        sudoku1[7][2]=3;
                        sudoku1[7][3]=10;
                        sudoku1[7][4]=7;
                        sudoku1[7][5]=9;
                        sudoku1[7][6]=2;
                        sudoku1[7][7]=11;
                        sudoku1[7][8]=6;
                        sudoku1[7][9]=8;
                        sudoku1[7][10]=12;
                        sudoku1[7][11]=5;
                        sudoku1[8][0]=11;
                        sudoku1[8][1]=6;
                        sudoku1[8][2]=8;
                        sudoku1[8][3]=12;
                        sudoku1[8][4]=1;
                        sudoku1[8][5]=4;
                        sudoku1[8][6]=3;
                        sudoku1[8][7]=5;
                        sudoku1[8][8]=10;
                        sudoku1[8][9]=7;
                        sudoku1[8][10]=2;
                        sudoku1[8][11]=9;
                        sudoku1[9][0]=12;
                        sudoku1[9][1]=11;
                        sudoku1[9][2]=1;
                        sudoku1[9][3]=4;
                        sudoku1[9][4]=5;
                        sudoku1[9][5]=7;
                        sudoku1[9][6]=10;
                        sudoku1[9][7]=2;
                        sudoku1[9][8]=3;
                        sudoku1[9][9]=6;
                        sudoku1[9][10]=9;
                        sudoku1[9][11]=8;
                        sudoku1[10][0]=2;
                        sudoku1[10][1]=5;
                        sudoku1[10][2]=9;
                        sudoku1[10][3]=3;
                        sudoku1[10][4]=11;
                        sudoku1[10][5]=1;
                        sudoku1[10][6]=8;
                        sudoku1[10][7]=6;
                        sudoku1[10][8]=12;
                        sudoku1[10][9]=4;
                        sudoku1[10][10]=10;
                        sudoku1[10][11]=7;

                        sudoku1[11][0]=8;
                        sudoku1[11][1]=7;
                        sudoku1[11][2]=10;
                        sudoku1[11][3]=6;
                        sudoku1[11][4]=12;
                        sudoku1[11][5]=3;
                        sudoku1[11][6]=4;
                        sudoku1[11][7]=9;
                        sudoku1[11][8]=1;
                        sudoku1[11][9]=2;
                        sudoku1[11][10]=5;
                        sudoku1[11][11]=11;


                          //permuting two numbers
                        int x=0,y=0;

                        x=1+rand()%12;
                        y=1+rand()%12;
                        while(x==y){

                            y=1+rand()%12;

                        }
                        for(int  i=0;i<12;i++){
                            for (int j=0;j<12;j++){
                                if (Sudoku_Empty[i][j] == x){
                                    Sudoku_Empty[i][j]=y;
                                    Sudoku_Solution[i][j]=y;

                                }

                                else if(Sudoku_Empty[i][j]==y){
                                    Sudoku_Empty[i][j]=x;
                                    Sudoku_Solution[i][j]=x;
                                }
                            } }

                                               // horizontal permutation
                        for(int i=0;i<=11;i++){
                            for(int j=0;j<=11;j++){
                                sudoku1hori[i][j]=sudoku1[11-i][j];
                            }
                        }

                        // copying the last values to the solution matrix and the empty one
                        for(int  i=0;i<12;i++){
                            for (int j=0;j<12;j++){
                                this->Sudoku_Empty[i][j]=sudoku1hori[i][j];
                                this->Sudoku_Solution[i][j]=sudoku1hori[i][j];


                            }}

                        // permuting two numbers randomly
                        x=1+rand()%12;
                        y=1+rand()%12;
                        while(x==y){

                            y=1+rand()%12;

                        }
                        for(int  i=0;i<12;i++){
                            for (int j=0;j<12;j++){
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

                        x=1+rand()%12;
                        y=1+rand()%12;
                        while(x==y){

                            y=1+rand()%12;

                        }
                        for(int  i=0;i<12;i++){
                            for (int j=0;j<12;j++){
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

                        x=1+rand()%12;
                        y=1+rand()%12;
                        while(x==y){

                            y=1+rand()%12;

                        }
                        for(int  i=0;i<12;i++){
                            for (int j=0;j<12;j++){
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
                        while(i<(5+x)){
                            a=rand() % 4;
                            b=rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=4+rand() % 4;
                            b=rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=8+rand() % 4;
                            b=rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=rand() % 4;
                            b=3+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=4+rand() % 4;
                            b=3+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=8+rand() % 4;
                            b=3+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=rand() % 4;
                            b=6+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                       while(i<(5+x)){
                            a=4+rand() % 4;
                            b=6+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=8+rand() % 4;
                            b=6+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }
                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=rand() % 4;
                            b=9+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }

                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=4+rand() % 4;
                            b=9+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }

                        i=0;
                        x=rand()%3;
                        while(i<(5+x)){
                            a=8+rand() % 4;
                            b=9+rand() % 3;
                            if(this->Sudoku_Empty[a][b]!=0){
                                i=i+1;
                                this->Sudoku_Empty[a][b]=0;}

                                    }


                        for(int i=0;i<12;i++){
                            for(int j=0;j<12;j++){
                                Sudoku_reset[i][j]=Sudoku_Empty[i][j];

                            }
                        }
                                                }

                    //reset the empty grill
                    void reset_grille(){
                        for(int i=0;i<12;i++){
                            for(int j=0; j<12; j++){
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
                        for(int i=0;i<12;i++){
                            if(this->Sudoku_Empty[i][ord]==nombre && i!=abs){
                                indicateur=0;
                                i=12;
                            }
                        }
                        return indicateur;
                    }

                    bool goodrow (int nombre,int abs, int ord){ // pour tester si la valeur existe sur la ligne
                        int indicateur=1;//indicateur d'existance du chiffre sur la colonne
                        for(int i=0;i<12;i++){
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

            if(ord<=2){
                for(int i=0;i<=3;i++){
                    for(int j=0;j<3;j++){
                        if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}

            }
            else {if(ord<=5){
                for(int i=0;i<=3;i++){
                    for(int j=3;j<6;j++){
                        if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                            nb=nb+1;
                            if(nb>=2){
                                indicateur=0;
                                i=99;
                                j=99;
                            }}}}}
                else {if(ord<=8){
                    for(int i=0;i<=3;i++){
                        for(int j=6;j<9;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb+1;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}

            }
                    else{for(int i=0;i<=3;i++){
                            for(int j=9;j<12;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}}}}}


         else {if (abs<=7){

                if(ord<=2){
                    for(int i=4;i<=7;i++){
                        for(int j=0;j<3;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}

                }
                else {if(ord<=5){
                    for(int i=4;i<=7;i++){
                        for(int j=3;j<6;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}}
                    else {if(ord<=8){
                        for(int i=4;i<=7;i++){
                            for(int j=6;j<9;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}

                }
                        else{for(int i=4;i<=7;i++){
                                for(int j=9;j<12;j++){
                                    if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                        nb=nb++;
                                        if(nb>=2){
                                            indicateur=0;
                                            i=99;
                                            j=99;
                                        }}}}}}}}
        else {

                if(ord<=2){
                    for(int i=8;i<=11;i++){
                        for(int j=0;j<3;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}

                }
                else {if(ord<=5){
                    for(int i=8;i<=11;i++){
                        for(int j=3;j<6;j++){
                            if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                nb=nb++;
                                if(nb>=2){
                                    indicateur=0;
                                    i=99;
                                    j=99;
                                }}}}}
                    else {if(ord<=8){
                        for(int i=8;i<=11;i++){
                            for(int j=6;j<9;j++){
                                if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                    nb=nb++;
                                    if(nb>=2){
                                        indicateur=0;
                                        i=99;
                                        j=99;
                                    }}}}

                }
                        else{for(int i=8;i<=11;i++){
                                for(int j=9;j<12;j++){
                                    if (nombre==this->Sudoku_Empty[i][j] && i!=abs && j!=ord) {
                                        nb=nb++;
                                        if(nb>=2){
                                            indicateur=0;
                                            i=99;
                                            j=99;
                                        }}}}}}}}
                return indicateur;
    }}
    ~sudoku12(){
        for(int i=0;i<12;i++){
           delete Sudoku_Empty[i];
            delete Sudoku_Solution[i];
                            }
        delete Sudoku_Empty;
        delete Sudoku_Solution;
    }


};




#endif // SUDOKU12_H

