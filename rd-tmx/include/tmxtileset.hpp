#pragma once
#include <string>
#include "pugixml.hpp"
#include "tmximage.hpp"

namespace rd {
	namespace tmx {
		class tileset final {
		public:
			explicit tileset(const pugi::xml_node& tileset_node);
			inline unsigned int get_firstgid() const { return _firstgid; }
			inline const std::string& get_name() const { return _name; }
			inline unsigned int get_tilewidth() const { return _tilewidth; }
			inline unsigned int get_tileheight() const { return _tileheight; }
			inline unsigned int get_spacing() const { return _spacing; }
			inline unsigned int get_margin() const { return _margin; }
			inline unsigned int get_tilecount() const { return _tilecount; }
			inline unsigned int get_columns() const { return _columns; }
			inline const image& get_image() const { return _image; }

		private:
			unsigned int _firstgid, 
				_tilewidth, _tileheight,
				_spacing, _margin,
				_tilecount, _columns;
			std::string _name;
			image _image;
		};
	}
}
