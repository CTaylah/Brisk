#pragma once

/*
    This is for use in Brisk applications only. This should
    NEVER be included within the Brisk project
*/


#include "Event/Event.h"

#include "Core/Application.h"
#include "Core/Log.h"
#include "Core/Input.h"

#include "Renderer/Vertex.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/VertexArray.h"
#include "Renderer/ShaderProgram.h"
#include "Renderer/Texture.h"
#include "Renderer/Renderer.h"
#include "Renderer/PerspectiveCameraController.h"

#include "Scene/Entity.h"

#include "Util/FileHandler.h"
#include "Util/GLTFLoader.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

#include <vector>