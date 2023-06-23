#pragma once

#include "Core/Log.h"

#include <string>
#include "tinygltf/tiny_gltf.h"

namespace Brisk{
    void testGLTF(){
        tinygltf::Model model;
        tinygltf::TinyGLTF loader;
        std::string err;
        std::string warn;

        bool ret = loader.LoadBinaryFromFile(&model, &err, &warn, "../assets/models/Cube.glb");
        
        

        if (!warn.empty()) {
            Log::warn(warn);
        }

        if (!err.empty()) {
            Log::error(err);
        }

        if (!ret) {
            Log::error("Failed to parse glTF\n");
        }

        else {
            Log::info("Loaded glTF\n");
        }
        
        int len = model.bufferViews[0].byteLength;

        Brisk::Log::error(len);
    }

}