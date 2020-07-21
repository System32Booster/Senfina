#pragma once

namespace Util
{
    /* Get the size of a file. */
    template <typename T>
    inline size_t FileSize(std::basic_string_view<T> filename)
    {
        auto path = std::filesystem::absolute(filename);
        return std::filesystem::file_size(path);
    }

    /* Check if the file exists in the directory. */
    template <typename T>
    inline bool FileExists(std::basic_string_view<T> filename)
    {
        auto path = std::filesystem::absolute(filename);
        return std::filesystem::exists(path);
    }

    /* Load data from a unicode file. */
    std::vector<uint8_t> FileLoad(std::wstring & filename);

    /* Load data from a file. */
    std::vector<uint8_t> FileLoad(std::string & filename);

    /* Write files to direct "filename" with data. */
    template <typename _Out, typename T>
    inline bool FileSave(std::basic_string_view<T> filename, std::vector<_Out>& data)
    {
        auto file = std::ofstream(filename, std::ofstream::binary);
        if (!file.is_open())
        {
            return false;
        }
        else
        {
            auto itr = std::ostreambuf_iterator<_Out>(file);
            std::copy(data.begin(), data.end(), itr);

            file.close();
            return true;
        }
    }

    template <typename T>
    inline std::basic_string<T> FileShortName(std::basic_string_view<T> filename, int lvl = 3)
    {
        static wchar_t tempBuf[1024] = { 0 };

        int c = 0;
        size_t i = 0;

        wchar_t* ptr = (wchar_t*)filename.data();

        tempBuf[0] = ptr[0];
        tempBuf[1] = ptr[1];
        tempBuf[2] = ptr[2];

        ptr += 3;

        for (i = _tcslen(ptr) - 1; i; i--)
        {
            if (ptr[i] == _T('\\')) c++;
            if (c == lvl) break;
        }

        if (c == lvl)
        {
            _stprintf_s(&tempBuf[3], _countof(tempBuf) - 3, _T("...%s"), &ptr[i]);
        }
        else return ptr - 3;

        return tempBuf;
    }

    template <typename T>
    inline std::basic_string<T> FileSmartSize(size_t size)
    {
        throw "Not implemented";
    }
}
