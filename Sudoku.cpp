#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Sudoku.h"
using namespace std;

void sudoku::Givequestion()
{
    printPuzzle();
}
void sudoku::ReadIn()
{
    int count=0;
    for(int i=0;i<12;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5]>>a[i][6]>>a[i][7]>>a[i][8]>>a[i][9]>>a[i][10]>>a[i][11];
    }
}
void sudoku::Solve()
{
    flag=0;
    backtrace(0);
    if(flag==0)
	cout<<0<<endl;
}
void sudoku::setPuzzle()
{
    int permute[9]={1,2,3,4,5,6,7,8,9};
    int hold, change;
    srand( time(0) );
    for (int i=0 ; i<9 ; i++) {
        change = rand()%9;
        hold = permute[i];
        permute[i] = permute[change];
        permute[change] = hold;
    }
    
    q[0][0]=q[1][3]=q[2][6]=q[3][1]=q[4][4]=q[5][7]=q[6][2]=q[7][5]=q[8][8]=q[9][2]=q[10][4]=q[11][6]=permute[0];
    q[0][1]=q[1][4]=q[2][7]=q[3][2]=q[4][5]=q[5][8]=q[6][0]=q[7][3]=q[8][6]=q[10][0]=q[11][5]=q[9][7]=permute[1];
    q[0][2]=q[1][5]=q[2][8]=q[3][0]=q[4][3]=q[5][6]=q[6][1]=q[7][4]=q[8][7]=q[11][1]=q[9][3]=q[10][8]=permute[2];
    q[1][0]=q[2][3]=q[0][6]=q[4][1]=q[5][4]=q[3][7]=q[7][2]=q[8][5]=q[6][8]=q[10][2]=q[11][4]=q[9][6]=permute[3];
    q[1][1]=q[2][4]=q[0][7]=q[4][2]=q[5][5]=q[3][8]=q[7][0]=q[8][3]=q[6][6]=q[11][0]=q[9][5]=q[10][7]=permute[4];
    q[1][2]=q[2][5]=q[0][8]=q[4][0]=q[5][3]=q[3][6]=q[7][1]=q[8][4]=q[6][7]=q[9][1]=q[10][3]=q[11][8]=permute[5];
    q[2][0]=q[0][3]=q[1][6]=q[5][1]=q[3][4]=q[4][7]=q[8][2]=q[6][5]=q[7][8]=q[11][2]=q[9][4]=q[10][6]=permute[6];
    q[2][1]=q[0][4]=q[1][7]=q[5][2]=q[3][5]=q[4][8]=q[8][0]=q[6][3]=q[7][6]=q[9][0]=q[10][5]=q[11][7]=permute[7];
    q[2][2]=q[0][5]=q[1][8]=q[5][0]=q[3][3]=q[4][6]=q[8][1]=q[6][4]=q[7][7]=q[10][1]=q[11][3]=q[9][8]=permute[8];
    
    for(int i=0;i!=3;i++)
        for(int j=9;j!=12;j++)
            q[i][j]=-1;
    
    for(int i=3;i!=6;i++)
    {
        for(int j=6;j!=9;j++)
        {
            q[i][j+3]=q[i][j];
            q[i][j]=-1;
        }
    }
    for(int i=6;i!=9;i++)
    {
        for(int j=3;j!=6;j++)
        {
            q[i][j+6]=q[i][j+3];
            q[i][j+3]=q[i][j];
            q[i][j]=-1;
        }
    }
    for(int i=9;i!=12;i++)
    {
        for(int j=0;j!=3;j++)
        {
            q[i][j+9]=q[i][j+6];
            q[i][j+6]=q[i][j+3];
            q[i][j+3]=q[i][j];
            q[i][j]=-1;
        }
    }
    
    
}


void sudoku::hollow()
{
    int deRow,deCol;
    srand( time(0) );
    for (int i=0 ; i<40 ;i++) {
        deRow = rand()%12;
        deCol = rand()%12;
        if(q[deRow][deCol]==0)
            i--;
        else if(q[deRow][deCol]==-1)
            i--;
        else
        q[deRow][deCol]=0;
    }
}

void sudoku::printPuzzle()
{
    setPuzzle();
    hollow();
    for (int i=0 ; i<12 ; i++) {
        for (int j=0 ; j<12 ; j++)
        {
            if(q[i][j]==-1)
                cout<<q[i][j];
            else
                cout<<" "<<q[i][j];
        }
        cout<<endl;
    }
}

bool sudoku::isPlace(int count){
    int row = count / 12;
    int col = count % 12;
    int j;
    for(j = 0; j < 12; ++j){
        if(a[row][j] == a[row][col] && j != col){
            return false;
        }
    }
    for(j = 0; j < 12; ++j){
        if(a[j][col] == a[row][col] && j != row){
            return false;
        }
    }
    int tempRow = row / 3 * 3;
    int tempCol = col / 3 * 3;
    for(j = tempRow; j < tempRow + 3;++j){
        for(int k = tempCol; k < tempCol + 3; ++k){
            if(a[j][k] == a[row][col] && j != row && k != col){
                return false;
            }
        }
    }
    return true;
}
void sudoku::backtrace(int count){
    if(count == 144){
	flag++;
	if(flag<2){
	
        cout<<flag<<endl;
        for(int i = 0; i < 12; ++i){
            for(int j =  0; j < 12; ++j){
                if(a[i][j]==-1)
                    cout<<a[i][j];
                else
                cout<<" "<<a[i][j];
            }
            cout<<endl;
        }
	}
	else if(flag==2)
	{
		cout<<flag<<endl;
	}
	else{}
    }
    int row = count / 12;
    int col = count % 12;
    if(a[row][col] == 0){
        for(int i = 1; i <= 9; ++i){
            a[row][col] = i;
            if(isPlace(count)){
                backtrace(count+1);
            }
        }
        a[row][col] = 0;//回溯
    }else{
        backtrace(count+1);
    }
}

