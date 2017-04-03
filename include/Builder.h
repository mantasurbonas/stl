#ifndef _STL_BUILDER_H_
#define _STL_BUILDER_H_

#include "stl/stl.h"
#include <vector>

namespace Stl {

	const Normal DOWN(0, 0, -1);
	const Normal UP(0, 0, 1);
	const Normal SOUTH(0, 1, 0);
	const Normal NORTH(0, -1, 0);
	const Normal EAST(1, 0, 0);
	const Normal WEST(-1, 0, 0);

	class Builder {
	private:
		std::vector<Entry> entries;

	public:
		void makeTriangle(const Normal & normal, const Vertex& a, const Vertex& b, const Vertex& c);

		void makeWall(const Normal & normal, const Vertex & a, const Vertex& b, const Vertex& c, const Vertex d);

		void makeCube(float x, float y, float z, float width, float length, float height);

		const std::vector<Entry>& elements()const;
	};
}
#endif
