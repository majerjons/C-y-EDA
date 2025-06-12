#include "algorithm.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << std::endl;
        return 1;
    }

    string path = "../../../";
    string file_name = argv[1];
    string full_path = path + file_name;
    GruposCoordenadas grupos;
    Matriz matrix;
    vector<vector<int>> distances;


    input_file(full_path, matrix, grupos);
    for (size_t i = 0; i < grupos.size(); ++i) 
    {
        findShortestPath(matrix, grupos[i]);
    }
    printMatrix(matrix);
    return 0;
}