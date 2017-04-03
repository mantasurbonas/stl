#ifndef _STL_ELEMENTS_H_
#define _STL_ELEMENTS_H_



namespace Stl {

	#pragma pack(1)
	struct Normal {
		float x;
		float y;
		float z;

		Normal() {}

		Normal(float ix, float iy, float iz) {
			x = ix;
			y = iy;
			z = iz;
		}

		Normal(float coords[3]) {
			x = coords[0];
			y = coords[1];
			z = coords[2];
		}
	};

	#pragma pack(1)
	struct Vertex {

		float x;
		float y;
		float z;

		Vertex() {}

		Vertex(float ix, float iy, float iz) {
			x = ix;
			y = iy;
			z = iz;
		}

		Vertex(float coords[3]) {
			x = coords[0];
			y = coords[1];
			z = coords[2];
		}
	};

	#pragma pack(1)
	struct Entry {
		Normal normal;

		Vertex vertex1;
		Vertex vertex2;
		Vertex vertex3;

		uint16_t attrByteCount;

		Entry()
			:attrByteCount(0) {
		}

		Entry(float n[3], float v1[3], float v2[3], float v3[3])
			: normal(n),
			vertex1(v1),
			vertex2(v2),
			vertex3(v3),
			attrByteCount(0) {
		}

		Entry(const Normal & n, const Vertex & v1, const Vertex & v2, const Vertex & v3)
			: normal(n),
			vertex1(v1),
			vertex2(v2),
			vertex3(v3),
			attrByteCount(0) {
		}
	};

}

std::ostream& operator <<(std::ostream& os, const Stl::Entry& e);

#endif
