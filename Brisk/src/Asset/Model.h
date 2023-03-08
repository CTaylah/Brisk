#include "Renderer/Mesh.h" 
#include <vector>

class Model
{
public:
    Model(const char* filePath);

private:
    const char* m_filePath;
    std::vector<Mesh*> meshes;
    bool loadData();

};