#include "tmxmap.hpp"

rd::tmx::map::map(const std::string& filename) {
	load_file(filename);
}

bool rd::tmx::map::load_file(const std::string& filename) {
	auto success = _doc.load_file(filename.c_str());
	if (success) {
		auto map_node = _doc.child("map");
		if (map_node.empty()) return false;
		
		_version = map_node.attribute("version").as_double();
		
		std::string or = map_node.attribute("orientation").as_string();
		if (or == "orthogonal")
			_orientation = orientation::orthogonal;
		else if (or == "isometric")
			_orientation = orientation::isometric;
		else if (or == "staggered")
			_orientation = orientation::staggered;
		else if (or == "hexagonal")
			_orientation = orientation::hexagonal;
		else
			_orientation = orientation::invalid;

		std::string ro = map_node.attribute("renderorder").as_string();
		if (ro == "right-down")
			_renderorder = renderorder::right_down;
		else if (ro == "right-up")
			_renderorder = renderorder::right_up;
		else if (ro == "left-down")
			_renderorder = renderorder::left_down;
		else if (ro == "left-up")
			_renderorder = renderorder::left_up;
		else
			_renderorder = renderorder::invalid;

		_width = map_node.attribute("width").as_uint();
		_height = map_node.attribute("height").as_uint();
		_tilewidth = map_node.attribute("tilewidth").as_uint();
		_tileheight = map_node.attribute("tileheight").as_uint();
		_hexsidelength = map_node.attribute("hexsidelength").as_uint();

		std::string sa = map_node.attribute("staggeraxis").as_string();
		if (sa == "x")
			_staggeraxis = staggeraxis::x;
		else if (sa == "y")
			_staggeraxis = staggeraxis::y;
		else
			_staggeraxis = staggeraxis::none;

		std::string si = map_node.attribute("staggerindex").as_string();
		if (si == "even")
			_staggerindex = staggerindex::even;
		if (si == "odd")
			_staggerindex = staggerindex::odd;
		else
			_staggerindex = staggerindex::none;

		std::string bgc = map_node.attribute("backgroundcolor").as_string();
		if (!bgc.empty()) {
			if (bgc.size() == 9) {
				_backgroundcolor.a = std::strtoul(bgc.substr(1, 2).c_str(), nullptr, 16);
				_backgroundcolor.r = std::strtoul(bgc.substr(3, 2).c_str(), nullptr, 16);
				_backgroundcolor.g = std::strtoul(bgc.substr(5, 2).c_str(), nullptr, 16);
				_backgroundcolor.b = std::strtoul(bgc.substr(7, 2).c_str(), nullptr, 16);
			}
			else if (bgc.size() == 7) {
				_backgroundcolor.a = 0xff;
				_backgroundcolor.r = std::strtoul(bgc.substr(1, 2).c_str(), nullptr, 16);
				_backgroundcolor.g = std::strtoul(bgc.substr(3, 2).c_str(), nullptr, 16);
				_backgroundcolor.b = std::strtoul(bgc.substr(5, 2).c_str(), nullptr, 16);
			}
		}

		_tilesets.clear();
		for (auto& tileset_node : map_node.children("tileset")) {
			if (tileset_node.empty()) return false;
			_tilesets.push_back(tileset(tileset_node));
		}

		_properties.clear();
		for (auto& property_node : map_node.child("properties").children("property")) {
			if (property_node.empty()) return false;
			_properties.push_back(property(property_node));
		}
		
		return true;
	}
	return false;
}
