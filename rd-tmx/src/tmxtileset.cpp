#include "tmxtileset.hpp"

rd::tmx::tileset::tileset(const pugi::xml_node& tileset_node)
	: _image(tileset_node.child("image")) {
	_firstgid = tileset_node.attribute("firstgid").as_uint();
	_name = tileset_node.attribute("name").as_string();
	_tilewidth = tileset_node.attribute("tilewidth").as_uint();
	_tileheight = tileset_node.attribute("tileheight").as_uint();
	_spacing = tileset_node.attribute("spacing").as_uint();
	_margin = tileset_node.attribute("margin").as_uint();
	_tilecount = tileset_node.attribute("tilecount").as_uint();
	_columns = tileset_node.attribute("columns").as_uint();
}
