#include "tmximage.hpp"

rd::tmx::image::image(const pugi::xml_node& image_node) {
	_source = image_node.attribute("source").as_string();
	
	std::string trans = image_node.attribute("trans").as_string();
	if (!trans.empty()) {
		_trans.r = std::strtoul(trans.substr(0, 2).c_str(), nullptr, 16);
		_trans.g = std::strtoul(trans.substr(2, 2).c_str(), nullptr, 16);
		_trans.b = std::strtoul(trans.substr(4, 2).c_str(), nullptr, 16);
	}

	_width = image_node.attribute("width").as_uint();
	_height = image_node.attribute("height").as_uint();
}
