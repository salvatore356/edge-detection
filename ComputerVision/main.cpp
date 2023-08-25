//
//  main.cpp
//  ComputerVision
//
//  Created by Salvatore on 29/7/23.
//

#include <iostream>
#include <format>

#include "Utils/Utils.hpp"
#include "TemplateMatching/TemplateMatching.hpp"
#include "MedianFilter/MedianFilter.hpp"
#include "GaussFilter/GaussFilter.hpp"
#include "EdgeDetection/Sobel.hpp"
#include "EdgeDetection/Prewitt.hpp"
#include "EdgeDetection/Roberts.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    
    
    
    vector<string> images = {
        "robert.jpg",
        "simple.jpg",
        "dog.jpg",
        "little-boy.jpg",
        "edge.jpg",
        "waldo-scene.jpg",
        "tree.jpg",
        "building.jpg",
        "structure.jpg",
        "castle.jpg"
    };
    
    for(auto &img : images) {
        EdgeDetection::Sobel::test(img);
        EdgeDetection::Prewitt::test(img);
        EdgeDetection::Roberts::test(img);
    }
    
    return 0;
}
