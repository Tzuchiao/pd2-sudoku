//
//  solve.cpp
//  c++sudoku
//
//  Created by TzuChiao Yeh on 2015/4/9.
//  Copyright (c) 2015年 TzuChiao Yeh. All rights reserved.
//

#include <stdio.h>
#include "Sudoku.h"
#include <iostream>
using namespace std;

int main()
{
    sudoku ss;
    ss.ReadIn();
    ss.Solve();
    
    return 0;
    
}
