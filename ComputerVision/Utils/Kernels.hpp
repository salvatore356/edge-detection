//
//  Kernels.hpp
//  ComputerVision
//
//  Created by Salvatore on 25/8/23.
//

#ifndef Kernels_hpp
#define Kernels_hpp

#include <stdio.h>

struct Kernel {
    vector<vector<int>> v;
    int height = 0, width = 0;
    
    Kernel(vector<vector<int>> kernel){
        this->height = (int)kernel.size();
        this->width = (int)kernel.front().size();
        this->v = kernel;
    }
    
    int at(int r, int c) {
        assert(r < v.size() && r >= 0);
        assert(c < v.front().size() && c >= 0);
        
        return v[r][c];
    }
};



#endif /* Kernels_hpp */
