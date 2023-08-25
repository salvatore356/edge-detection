//
//  Prewitt.hpp
//  ComputerVision
//
//  Created by Salvatore on 24/8/23.
//

#ifndef Prewitt_hpp
#define Prewitt_hpp

#include <stdio.h>

#include "../Utils/Utils.hpp"

namespace EdgeDetection {

    Image prewitt(Image& img) {
        // Define Sobel kernels
        Image filtered(img.height, img.width, img.channels);
        
        Kernel X({ { -1, 0, 1 }, { -1, 0, 1 }, { -1, 0, 1 } });
        Kernel Y({ { -1, -1, -1 }, {  0,  0,  0 }, {  1,  1,  1 } });

        vector<Kernel> kernels = { X, Y };

        // Apply Prewitt operator to each pixel
        for (int r = 1; r < img.height - 1; ++r)
            for (int c = 1; c < img.width - 1; ++c)
                applyKernels (img, filtered, r, c, kernels);
        
        return filtered;
    }

Image prewittSimple(Image& img) {

    Image filtered(img.height, img.width, img.channels);
    
    // Define Prewitt kernels
    int prewittX[3][3] = { { -1, 0, 1 }, { -1, 0, 1 }, { -1, 0, 1 } };
    int prewittY[3][3] = { { -1, -1, -1 }, {  0,  0,  0 }, {  1,  1,  1 } };

    // Apply Prewitt operator to each pixel
    for (int y = 1; y < img.height - 1; ++y) {
        for (int x = 1; x < img.width - 1; ++x) {

            Pixel gradX, gradY;
            int rr, cc;
            
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    rr =  y + i - 1; cc = x + j - 1;
                    gradX += img.at(rr, cc) * prewittX[i][j];
                    gradY += img.at(rr, cc) * prewittY[i][j];
                }
            }
            
            filtered.at(y, x) = sqrt( gradX.avg() * gradX.avg() + gradY.avg() * gradY.avg() );
        }
    }
    
    return filtered;
}

    namespace Prewitt {
        void test() {
            auto img = readJPG("edge.jpg");
            auto prewitt_filtered = prewitt(*img);
            writeJPG(prewitt_filtered, "prewitt.jpg");
            
            auto prewitt_filtered2 = prewittSimple(*img);
            writeJPG(prewitt_filtered2, "prewitt2.jpg");
            
            printf("prewitt...\n");
        }
    
        void test(string img_path) {
            auto img = readJPG(img_path);
            auto prewitt_filtered = prewitt(*img);
            writeJPG(prewitt_filtered, "prewitt-" + img_path);
        }
    }
}
#endif /* Prewitt_hpp */
