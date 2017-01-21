#pragma once
#include <string>
#include "pugixml.hpp"

namespace rd {
	namespace tmx {
		class property final {
		public:
			enum class type {
				string, integer, floating_point, boolean, color, file
			};

			struct color {
				std::uint8_t r, g, b, a;
			};

			explicit property(const pugi::xml_node& property_node);
			inline const std::string& get_name() const { return _name; }
			inline type get_type() const { return _type; }
			inline std::string as_string() const { return _val.stringval; }
			inline int as_int() const { return _val.intval; }
			inline float as_float() const { return _val.floatval; }
			inline bool as_bool() const { return _val.boolval; }
			inline color as_color() const { return _val.colorval; }

		private:
			std::string _name;
			type _type;
			union value {
				const char* stringval;
				int intval;
				float floatval;
				bool boolval;
				color colorval{ 0, 0, 0 };
			} _val;
		};
	}
}
