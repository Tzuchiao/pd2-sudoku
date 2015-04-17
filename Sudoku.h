#ifndef ____sudoku__
#define ____sudoku__

#include <stdio.h>

class sudoku
{
public:
    void Givequestion();
    void ReadIn();
    void Solve();
    void setPuzzle();
    void hollow();
    void printPuzzle();
    bool isPlace(int count);
    void backtrace(int count);

    
private:
    int q[12][12];
    int a[12][12];
    int flag;
    
};




#endif /* defined(____sudoku__) */

