#pragma pack(push, 1)
#include "stl/stl.h"
#pragma pack(pop)


std::ostream& operator <<(std::ostream& os, const Stl::Entry& e){
 os << e.normal.x << " " << e.normal.y << " " << e.normal.z << std::endl
	 << "  " << e.vertex1.x << " " << e.vertex1.y << " " << e.vertex1.z << std::endl
	 << "  " << e.vertex2.x << " " << e.vertex2.y << " " << e.vertex2.z << std::endl
	 << "  " << e.vertex3.x << " " << e.vertex3.y << " " << e.vertex3.z << std::endl
	 << e.attrByteCount << std::endl;
 return os;
}