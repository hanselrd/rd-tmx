#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "pugixml.hpp"
#include "tmxtileset.hpp"
#include "tmxproperty.hpp"

namespace rd {
	namespace tmx {
		class map final {
		public:
			enum class orientation { 
				orthogonal, isometric, staggered, hexagonal, invalid 
			};

			enum class renderorder {
				right_down, right_up, left_down, left_up, invalid
			};

			enum class staggeraxis {
				x, y, none
			};

			enum class staggerindex {
				even, odd, none
			};

			struct backgroundcolor {
				std::uint8_t r, g, b, a;
			};

			map() = default;
			explicit map(const std::string& filename);
			bool load_file(const std::string& filename);
			inline double get_version() const { return _version; }
			inline orientation get_orientation() const { return _orientation; }
			inline renderorder get_renderorder() const { return _renderorder; }
			inline unsigned int get_width() const { return _width; }
			inline unsigned int get_height() const { return _height; }
			inline unsigned int get_tilewidth() const { return _tilewidth; }
			inline unsigned int get_tileheight() const { return _tileheight; }
			inline unsigned int get_hexsidelength() const { return _hexsidelength; }
			inline staggeraxis get_staggeraxis() const { return _staggeraxis; }
			inline staggerindex get_staggerindex() const { return _staggerindex; }
			inline backgroundcolor get_backgroundcolor() const { return _backgroundcolor; }
			inline const std::vector<tileset>& get_tilesets() const { return _tilesets; }
			inline const std::vector<property>& get_properties() const { return _properties; }

		private:
			pugi::xml_document _doc;
			double _version;
			orientation _orientation;
			renderorder _renderorder;
			unsigned int _width, _height,
				_tilewidth, _tileheight,
				_hexsidelength;
			staggeraxis _staggeraxis;
			staggerindex _staggerindex;
			backgroundcolor _backgroundcolor{ 0, 0, 0, 0 };
			std::vector<tileset> _tilesets;
			std::vector<property> _properties;
		};
	}
}
