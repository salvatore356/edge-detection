//
//  Roberts.hpp
//  ComputerVision
//
//  Created by Salvatore on 24/8/23.
//

#ifndef Roberts_hpp
#define Roberts_hpp

#include <stdio.h>

#include "../Utils/Utils.hpp"

namespace EdgeDetection {

    Image roberts(Image& img) {
        // Define Sobel kernels
        Image filtered(img.height, img.width, img.channels);
        
        Kernel X({ { 1,  0 }, { 0, -1 } });
        Kernel Y({{  0, 1 }, { -1, 0 } });
        
        vector<Kernel> kernels = { X, Y };
        
        // Apply Roberts operator to each pixel
        for (int r = 1; r < img.height - 1; ++r)
            for (int c = 1; c < img.width - 1; ++c)
                applyKernels (img, filtered, r, c, kernels);
        
        return filtered;
    }

    Image robertsSimple(Image& img) {
        Image filtered(img.height, img.width, img.channels);
        
        // Define Roberts kernels
        int robertsX[2][2] = { { 1, 0 }, { 0, -1 }};
        int robertsY[2][2] = { { 0, 1 }, { -1, 0 }};

        // Apply Roberts operator to each pixel
        for (int y = 1; y < img.height - 1; ++y) {
            for (int x = 1; x < img.width - 1; ++x) {

                Pixel gradX, gradY;
                int rr, cc;
                
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        rr =  y + i - 1; cc = x + j - 1;
                        gradX += img.at(rr, cc) * robertsX[i][j];
                        gradY += img.at(rr, cc) * robertsY[i][j];
                    }
                }
                
                filtered.at(y, x) = sqrt( gradX.avg() * gradX.avg() + gradY.avg() * gradY.avg() );
            }
        }
        
        return filtered;
    }

    namespace Roberts {
        void test() {
            
            auto img = readJPG("waldo-scene.jpg");
            auto roberts_filtered = roberts(*img);
            writeJPG(roberts_filtered, "roberts.jpg");
            
            auto roberts_filtered2 = robertsSimple(*img);
            writeJPG(roberts_filtered2, "roberts2.jpg");
            
            printf("roberts...\n");
        }
    
        void test(string img_path) {
            auto img = readJPG(img_path);
            auto roberts_filtered = roberts(*img);
            writeJPG(roberts_filtered, "roberts-" + img_path);
        }
    }
}

#endif /* Roberts_hpp */
