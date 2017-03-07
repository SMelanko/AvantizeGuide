#include "pch.h"

#include "FileMgr.h"

namespace fproc
{

//
// Definition of the File class.
//

std::string File::Read(const bfs::path& filename)
{
	bfs::ifstream ifs{ filename };

	if (!ifs) {
		const auto msg = boost::str(boost::format{
			"File::Read: Can't open \"%1%\" file." } % filename.string());
		BOOST_THROW_EXCEPTION(std::runtime_error{ msg });
	}

	std::string data;
	data.assign(std::istreambuf_iterator<char>(ifs),
		std::istreambuf_iterator<char>());
	
	return data;
}

void File::Write(const bfs::path& filename, const std::string& text)
{
	bfs::ofstream ofs{ filename };

	if (!ofs) {
		const auto msg = boost::str(boost::format{
			"File::Write: Can't open \"%1%\" file." } % filename.string());
		BOOST_THROW_EXCEPTION(std::runtime_error{ msg });
	}

	ofs << text;
}

} // namespace fproc
