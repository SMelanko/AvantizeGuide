#pragma once

namespace fproc
{

//
// Declaration of the File class.
//

class File
{
	//
	// Public interface.
	//
public:
	//! Reads an entire file.
	std::string Read(const bfs::path& filename);
	//! Writes data to the file.
	void Write(const bfs::path& filename, const std::string& text);
};

using FileShPtr = std::shared_ptr<File>;

} // namespace fproc
