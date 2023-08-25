//
//  Sobel.hpp
//  ComputerVision
//
//  Created by Salvatore on 24/8/23.
//

#ifndef Sobel_hpp
#define Sobel_hpp

#include <stdio.h>

#include "../Utils/Utils.hpp"

namespace EdgeDetection {

    Image sobel(Image& img) {
        // Define Sobel kernels
        Image filtered(img.height, img.width, img.channels);
        
        Kernel X({ { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } });
        Kernel Y({ { -1, -2, -1 }, {  0,  0,  0 }, {  1,  2,  1 } });

        vector<Kernel> kernels = { X, Y };

        // Apply Sobel operator to each pixel
        for (int r = 1; r < img.height - 1; ++r)
            for (int c = 1; c < img.width - 1; ++c)
                applyKernels (img, filtered, r, c, kernels);
        
        return filtered;
    }

Image sobelSimple(Image& img) {
    
    Image filtered(img.height, img.width, img.channels);
    
    // Define Sobel kernels
    int sobelX[3][3] = {{-1,  0,  1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobelY[3][3] = {{-1, -2, -1}, { 0, 0, 0}, { 1, 2, 1}};

    // Apply Sobel operator to each pixel
    for (int y = 1; y < img.height - 1; ++y) {
        for (int x = 1; x < img.width - 1; ++x) {

            Pixel gradX, gradY;
            int rr, cc;
            
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    rr =  y + i - 1; cc = x + j - 1;
                    gradX += img.at(rr, cc) * sobelX[i][j];
                    gradY += img.at(rr, cc) * sobelY[i][j];
                }
            }
            
            filtered.at(y, x) = sqrt( gradX.avg() * gradX.avg() + gradY.avg() * gradY.avg() );
        }
    }
    
    return filtered;
}

    namespace Sobel {
        void test() {
            auto img = readJPG("dog.jpg");
            auto sobel_filtered = sobel(*img);
            auto sobel_filtered2 = sobelSimple(*img);
            
            writeJPG(sobel_filtered, "sobel.jpg");
            writeJPG(sobel_filtered2, "sobel2.jpg");
            printf("sobel...\n");
        }
    
        void test(string img_path) {
            auto img = readJPG(img_path);
            auto sobel_filtered = sobel(*img);
            writeJPG(sobel_filtered, "sobel-" + img_path);
        }
    }
}

#endif /* Sobel_hpp */
