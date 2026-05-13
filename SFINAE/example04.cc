#include <unordered_map>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

template<class T, T v>
struct m_integeral_trait {
    static constexpr T value = v;
};

template<bool v>
struct m_bool_trait : m_integeral_trait<bool, v> {

};

// template<class Container>
// std::string join(Container&& c, const std::string& split) {
//     std::stringstream ssm;
    
//     bool is_first = true;
//     for (auto& item : std::forward<Container>(c)) {
//         if (is_first) {
//             ssm << item << split;
//             is_first = false;
//         } else {
//             ssm << item;
//         }
//     }

//     return ssm.str();
// }

template<class Key, class Val>
std::ostream& operator<<(std::ostream& os, const std::pair<Key, Val>& p) {
    return os << p.first << ":" << p.second;

}

template<class Key, class Val>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, Val>& mp) {
    os << "{ ";

    for (auto it : mp) {
        if constexpr (std::is_convertible<Key, std::string>::value || std::is_convertible<Key, char*>::value) {
            os << "\"" << it.first << "\"";
        } else {
            os << it.first;
        }

        os << ":";

        if constexpr (std::is_convertible<Val, std::string>::value || std::is_convertible<Val, char*>::value) {
            os << "\"" << it.second << "\" ";
        } else {
            os << it.second << ' ';
        }
    }
    
    return os << '}';
}
using std::unordered_map;

template<class Printable>
std::ostream& operator<<(std::ostream& os, const std::vector<Printable>& mp) {
    os << "[ ";

    for (auto it : mp) {
        if constexpr (std::is_convertible<Printable, std::string>::value || std::is_convertible<Printable, char*>::value) {
            os << "\"" << it << "\" ";
        } else {
            os << it << ' ';
        }
    }
    
    return os << ']';
}

int main(int argc, char const *argv[])
{

    unordered_map<int, int> mp;
    for (int i = 0; i < 4; ++i) mp[i] = i;
    std::cout << mp << std::endl;

    unordered_map<std::string, std::string> mp_str;
    mp_str["aaa"] = "bbb";
    mp_str["bbb"] = "ddd";

    std::cout << mp_str << std::endl;

    std::vector<int> arr{1, 2, 3, 4};
    std::cout << arr << std::endl;

    std::vector<const char*> arr1{"1", "2", "3", "4"};
    std::cout << arr1 << std::endl;


    return 0;
}
