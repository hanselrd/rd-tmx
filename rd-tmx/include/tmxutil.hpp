#pragma once
#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

namespace rd {
	namespace tmxutil {
		namespace detail {
			inline std::string& ltrim(std::string& s) {
				s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::function<int(int)>(std::isspace))));
				return s;
			}

			inline std::string& rtrim(std::string& s) {
				s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::function<int(int)>(std::isspace))).base(), s.end());
				return s;
			}
		}

		inline std::string& trim(std::string& s) {
			return detail::ltrim(detail::rtrim(s));
		}
	}
}