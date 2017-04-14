#include <util/string_utils.hpp>


std::vector<std::string> splitString(const std::string &s, const std::string &d)
{
    std::vector<std::string> result;

    char *cStr = new char[s.size() + 1];
    strcpy(cStr, s.c_str());
    char *token = strtok(cStr, d.c_str());
    while (token)
    {
        result.push_back(std::string(token));
        token = strtok(NULL, d.c_str());
    }

    delete[] cStr;
    return result;
}

bool startsWith(const std::string &s, const std::string &t)
{
    if (t.empty())
        return true;
    return s.find(t) == 0;
}

bool endsWith(const std::string &s, const std::string &t)
{
    if (t.size() > s.size())
        return false;
    if (t.empty())
        return true;
    return s.find(t) == s.size() - t.size();
}
