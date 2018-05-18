#ifndef O3D_H
#define O3D_H

#include <vector>
#include <O3DS.h>

using namespace std;

class O3D : public O3DS{

protected:

    vector<_vertex3i> triangles;
public:

    void draw_lines();
	void draw_fill();
    void draw_chess();

};

#endif
