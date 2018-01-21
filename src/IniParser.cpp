#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include "IniParser.h"

std::regex IniParser::RE_SECTION(R"(\[(\w+)\])");
std::regex IniParser::RE_KEY_VALUE(R"((\S+)\s+=\s+(\S+))");

IniParser::IniParser(std::ifstream &file) {
  std::string line;
  std::string section_name;
  std::string key;
  std::string value;
  bool is_section = false;
  bool is_key_value = false;
  std::smatch section_matches;
  std::smatch key_value_matches;

  while (file.good()) {
    std::getline(file, line);

    is_section = std::regex_search(line, section_matches, IniParser::RE_SECTION)
                 && section_matches.size() == 2;
    is_key_value = std::regex_search(line, key_value_matches, IniParser::RE_KEY_VALUE)
                   && key_value_matches.size() == 3;

    if (is_section) {
      section_name = section_matches[1];
    } else if (is_key_value) {
      key = key_value_matches[1];
      value = key_value_matches[2];
    }

    if (!section_name.empty() && is_key_value) {
      this->sections[section_name][key] = value;
    }

    key.clear();
    value.clear();
    is_section = false;
    is_key_value = false;
  }
}

bool IniParser::isHaveSection(std::string section_name) {
  return this->sections.find(section_name) != this->sections.end();
};

bool IniParser::isHaveParam(std::string section_name, std::string param_name) {
  return this->sections.find(section_name)->second.find(param_name) != this->sections.find(section_name)->second.end();
};

int IniParser::getValueInt(std::string section_name, std::string param_name) {
  return std::stoi(this->sections[section_name][param_name]);
}

double IniParser::getValueDouble(std::string section_name, std::string param_name) {
  return std::stod(this->sections[section_name][param_name]);
}

std::string IniParser::getValue(std::string section_name, std::string param_name) {
  return this->sections[section_name][param_name];
}

//template <typename T>
//T IniParser::getValueT(std::string section_name, std::string param_name) {
//  return this->sections[section_name][param_name];
//}


