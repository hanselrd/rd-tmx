#include "tmxproperty.hpp"

rd::tmx::property::property(const pugi::xml_node& property_node) {
	_name = property_node.attribute("name").as_string();

	std::string typ = property_node.attribute("type").as_string();
	if (typ == "int")
		_type = type::integer;
	else if (typ == "float")
		_type = type::floating_point;
	else if (typ == "bool")
		_type = type::boolean;
	else if (typ == "color")
		_type = type::color;
	else if (typ == "file")
		_type = type::file;
	else
		_type = type::string;

	std::string temp;
	switch (_type) {
	case type::integer:
		_val.intval = property_node.attribute("value").as_int();
		break;
	case type::floating_point:
		_val.floatval = property_node.attribute("value").as_float();
		break;
	case type::boolean:
		_val.boolval = property_node.attribute("value").as_bool();
		break;
	case type::color:
		temp = property_node.attribute("value").as_string();
		_val.colorval.a = std::strtoul(temp.substr(1, 2).c_str(), nullptr, 16);
		_val.colorval.r = std::strtoul(temp.substr(3, 2).c_str(), nullptr, 16);
		_val.colorval.g = std::strtoul(temp.substr(5, 2).c_str(), nullptr, 16);
		_val.colorval.b = std::strtoul(temp.substr(7, 2).c_str(), nullptr, 16);
		break;
	case type::file:
	case type::string:
		_val.stringval = property_node.attribute("value").as_string();
		break;
	}
}