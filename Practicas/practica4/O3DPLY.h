#ifndef O3DPLY_H
#define O3DPLY_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "vertex.h"
#include <O3D.h>

class O3DPLY : public O3D{
public:
    O3DPLY();
    int open(const string &File_name);
    void read(vector<_vertex3f> &Vertices, vector<_vertex3i> &Triangles);
    void close();
    void draw();

  private:
    void get_token(std::istringstream &Line_stream1,std::string &Token1);
    bool get_new_line(std::ifstream &File,std::istringstream &Line_stream);

    std::ifstream File;
};

#endif // O3DPLY_H
