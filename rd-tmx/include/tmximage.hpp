#pragma once
#include <cstdint>
#include <string>
#include "pugixml.hpp"

namespace rd {
	namespace tmx {
		class image final {
		public:
			struct transparentcolor {
				std::uint8_t r, g, b;
			};

			explicit image(const pugi::xml_node& image_node);
			inline const std::string& get_source() const { return _source; }
			inline transparentcolor get_transparentcolor() const { return _trans; }
			inline unsigned int get_width() const { return _width; }
			inline unsigned int get_height() const { return _height; }

		private:
			std::string _source;
			transparentcolor _trans{ 0, 0, 0 };
			unsigned int _width, _height;
		};
	}
}
