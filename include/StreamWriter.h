#ifndef _STL_STREAM_WRITER_H_
#define _STL_STREAM_WRITER_H_

#include <fstream>

#pragma pack(push, 1)
#include "stl/stl.h"
#pragma pack(pop)

namespace Stl {

	class StreamWriter {

		protected:
			std::ofstream _ostr;
			uint32_t _numberOfTriangles;
			bool _started;

			StreamWriter(const StreamWriter& o);
			StreamWriter& operator =(const StreamWriter& o);

			void start();

		public:
			StreamWriter(const std::string& fname, int n = -1);
			virtual ~StreamWriter();

			void write(const Stl::Entry& what);
			void write(const Stl::Entry* const what, unsigned int howMany);
			void write(const std::vector<Stl::Entry> entries);

			void close();
	};
}

#endif
