// list of character struct sorting method
#include <iostream>
#include <string>
#include <vector>
#include <list>

struct character {
  std::string pinyin;
  std::string is_varient;
  std::string tone;
  std::string strokes;

  character(std::string pinyin, std::string is_varient, std::string tone, std::string strokes) {
    this->pinyin = pinyin;
    this->is_varient = is_varient;
    this->tone = tone == "0" ? std::to_string(5): tone;
    this->strokes = strokes;
  }

  // sort overload compare character object
  bool operator <(const character & characterObj)  const {
    if (pinyin != characterObj.pinyin) return pinyin < characterObj.pinyin;  // sort according to pinyin if not same (1)
    else if (is_varient != characterObj.is_varient) return is_varient < characterObj.is_varient; // sort according to varient forms, varient form after (2)
    else if (tone != characterObj.tone) return tone < characterObj.tone; // sort according to tone if not same (3)
    else if (strokes.length() != characterObj.strokes.length()) return strokes.length() < characterObj.strokes.length(); // sort according to number of strokes (4)
    else return strokes.compare(characterObj.strokes) < 0 ? true : false; // sort according to stroke order
    return false;
  }
  
};

character* new_character(std::string pinyin, int is_varient, int tone, std::string strokes) {
    struct character* character = (struct character*) malloc(sizeof(struct character));
    character->pinyin = pinyin;
    character->is_varient = is_varient;
    character->tone = tone;
    character->strokes = strokes;
    return (character);
}

int main() {
  
  std::string s;
  std::list<character> characters;
  int lines = 0;
  while(std::getline(std::cin, s) && s != "~"){
    if (lines > 2000) break; 
    else lines++;

    // std::cout << s << std::endl;
    // parse lines
    // size_t last = 0;
    // size_t next = 0;
    // std::cout << last << next;
    // std::string delimiter = " ";
    // std::vector<std::string> splits;

    std::string pinyin = s.substr(0, s.find(" "));
    // std::cout << pinyin << "\n";
    s = s.substr(s.find(" ") + 1, s.length());
    // std::cout << s << "\n";
    std::string is_varient =  s.substr(0, s.find(" "));
    s = s.substr(s.find(" ") + 1, s.length());
    // std::cout << s << "\n";
    std::string tone = s.substr(0, s.find(" "));
    s = s.substr(s.find(" ") + 1, s.length());
    // std::cout << s.length() << "\n";
    std::string strokes = s;
    

    // while ((next = s.find(delimiter, last)) != std::string::npos)  {   
    
    //   // std:: cout << s.substr(last, next-last) << " ";   
    //   splits.push_back(s.substr(last, next-last));

    //   last = next + 1; 
    // } 
    // // std::cout << s.substr(last) << std::endl;
    // splits.push_back(s.substr(last));

    // character new_ch = character(splits[0], splits[1], splits[2], splits[3]);
    character new_ch = character(pinyin, is_varient, tone, strokes);
    // character new_ch = character("hi", "hi", "hi", "hi");
    characters.push_back(new_ch);
  }
  // std::cout << characters.size();
  characters.sort();
 
  std::list<character>::iterator it;
  for (it = characters.begin(); it != characters.end(); it++) {
    std::string temp = it->tone == "5" ? "0" : it->tone;
    std::cout << it->pinyin << " " << it->is_varient << " " << temp << " " << it->strokes << "\n";
  }
  std::cout << "\n";
}