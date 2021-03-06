#include "./misc.h"
#include "./nativefilestream.h"

#include <streambuf>

using namespace std;

namespace CppUtilities {

/*!
 * \brief Reads all contents of the specified file in a single call.
 * \throws Throws std::ios_base::failure when an error occurs or the specified \a maxSize
 *         would be exceeded.
 */
std::string readFile(const std::string &path, std::string::size_type maxSize)
{
    NativeFileStream file;
    file.exceptions(ios_base::failbit | ios_base::badbit);
    file.open(path, ios_base::in | ios_base::binary);
    file.seekg(0, ios_base::end);
    string res;
    const auto size = static_cast<string::size_type>(file.tellg());
    if (maxSize != string::npos && size > maxSize) {
        throw ios_base::failure("File exceeds max size");
    }
    res.reserve(size);
    file.seekg(ios_base::beg);
    res.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return res;
}
} // namespace CppUtilities
