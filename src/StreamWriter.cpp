
#pragma pack(push, 1)
#include "stl/stl.h"
#pragma pack(pop)

#include "stl/StreamWriter.h"

#include <fstream>

using namespace std;
using namespace Stl;

StreamWriter::StreamWriter(const string& fname, int n)
	:_ostr(fname, ios::binary),
	_numberOfTriangles(n),
	_started(false) {
	;
}

StreamWriter::~StreamWriter() {
	close();
}


void StreamWriter::write(const Entry& what) {
	if (!_started)
		start();

	_ostr.write((const char*)&what, sizeof Entry);
}

void StreamWriter::write(const Entry* const what, unsigned int howMany) {
	_numberOfTriangles = howMany;
	start();

	for (unsigned int i = 0; i < howMany; i++)
		write(what[i]);
}

void StreamWriter::write(const std::vector<Entry> entries) {
	_numberOfTriangles = entries.size();
	start();

	for (auto i = entries.begin(); i != entries.end(); i++)
		write(*i);
}

void StreamWriter::close() {
	_ostr.flush();
}


void StreamWriter::start() {
	if (_started)
		throw runtime_error("already wrote header");

	if (_numberOfTriangles <= 0)
		throw runtime_error("specify number of triangles first");

	char header[80];
	memset(header, ' ', sizeof header);
	snprintf(header, sizeof header, "Vive Sculptor v0.0.1");
	_ostr.write(header, sizeof header);

	_ostr.write((const char*)&_numberOfTriangles, sizeof _numberOfTriangles);

	_started = true;
}