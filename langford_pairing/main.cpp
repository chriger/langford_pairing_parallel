//
//  main.cpp
//  langford_pairing
//
//  Created by Gerloff, Christian on 13.11.14.
//  Copyright (c) 2014 Gerloff, Christian. All rights reserved.
//

#include <iostream>
#include "tbb/tbb.h"
#include "langford_solver.h"
using namespace tbb;
using namespace std;

int main(int argc, const char * argv[]) {
    // Define how many threads should be used
    tbb::task_scheduler_init init(4);
    
    // Size of the langford pairing problem 4m & 4m-1 [3, 4, 7, 8, 11, 12, 15, 16, 19, 20, 23, 24,...]
    char n = 8;
    
    tick_count t0 = tick_count::now();
    LangfordSolver* root = new(tbb::task::allocate_root()) LangfordSolver(0, 1, 2*n);
    tbb::task::spawn_root_and_wait(*root);
    
    tick_count t1 = tick_count::now();
    
    printf("Zeit für Algorithmus: %g seconds\n", (t1-t0).seconds());
    
    cout << "Lösungen: " << LangfordSolver::getSolutionCounter() << endl;
    return 0;
}
