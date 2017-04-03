#ifndef _STL_STREAM_READER_H_
#define _STL_STREAM_READER_H_

#include <iostream>
#include "stl/stl.h"

namespace Stl {

	class StreamReader {
	private:
		std::istream& _istr;
		uint32_t _numberOfTriangles;

		StreamReader(const StreamReader& o);
		StreamReader& operator = (const StreamReader& o);

	public:
		StreamReader(std::istream& istr) :_istr(istr) {
			char buff[80];
			istr.read(buff, sizeof buff);
			istr.read((char*)&_numberOfTriangles, sizeof _numberOfTriangles);
		}

		bool read(Stl::Entry * const where) {
			_istr.read((char*)where, sizeof Stl::Entry);

			return _istr.good() && !_istr.eof();
		}

		int size()const {
			return _numberOfTriangles;
		}
	};
}

#endif
