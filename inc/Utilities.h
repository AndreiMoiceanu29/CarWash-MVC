#ifndef H_UTILS
#define H_UTILS
#include <vector>
#include <string>
#include <iostream>
class Utilities
{
public:
	Utilities();
	static std::vector<std::string> split(const char *str, char c = ' '){
    	std::vector<std::string> result;
    	do{
        	const char *begin = str;
        	while(*str != c && *str)
            	str++;
        	result.push_back(std::string(begin, str));
    	}while (0 != *str++);

    return result;
	}
	template<typename Base, typename T2>
	static inline bool instanceof(const T2*) {
   		return std::is_base_of<Base, T2>::value;
	}
	~Utilities();
	
};
#endif