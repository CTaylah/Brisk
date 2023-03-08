//ONLY INCLUDE THIS FILE FOR APPLICATIONS
//DO NOT INCLUDE THIS FILE ANYWHERE IN THE ENGINE
#include "Renderer/ShaderProgram.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Structures.h"
#include "Renderer/Texture.h"
#include "Renderer/Mesh.h"
#include "Renderer/Renderer.h"


#include "Asset/Model.h"

#include <iostream>
#include <vector>

#include "glad/glad.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "glfw/glfw3.h"

#ifdef APIENTRY
#undef APIENTRY
#endif

#include "glm/glm.hpp"


#include "spdlog/spdlog.h"
//#define TARGET_FPS = 60;

