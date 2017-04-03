#include "stl\Builder.h"

using namespace Stl;

void Builder::makeTriangle(const Normal & normal, const Vertex& a, const Vertex& b, const Vertex& c) {
	entries.push_back(Entry(normal, a, b, c));
}

void Builder::makeWall(const Normal & normal,
	const Vertex & a, const Vertex& b, const Vertex& c, const Vertex d) {

	makeTriangle(normal, a, b, c);
	makeTriangle(normal, a, c, d);
}

void Builder::makeCube(float x1, float y1, float z1, float width, float length, float height) {

	float x2 = x1 + width;
	float y2 = y1 + length;
	float z2 = z1 + height;

	makeWall(DOWN, Vertex(x1, y1, z1), Vertex(x2, y1, z1), Vertex(x2, y2, z1), Vertex(x1, y2, z1));
	makeWall(UP,   Vertex(x1, y1, z2), Vertex(x2, y1, z2), Vertex(x2, y2, z2), Vertex(x1, y2, z2));

	makeWall(NORTH, Vertex(x2, y2, z2), Vertex(x1, y2, z2), Vertex(x1, y2, z1), Vertex(x2, y2, z1));
	makeWall(SOUTH, Vertex(x2, y1, z2), Vertex(x1, y1, z2), Vertex(x1, y1, z1), Vertex(x2, y1, z1));

	makeWall(EAST, Vertex(x2, y1, z1), Vertex(x2, y2, z1), Vertex(x2, y2, z2), Vertex(x2, y1, z2));
	makeWall(WEST, Vertex(x1, y1, z1), Vertex(x1, y2, z1), Vertex(x1, y2, z2), Vertex(x1, y1, z2));
}

const std::vector<Entry>& Builder::elements()const {
	return entries;
}