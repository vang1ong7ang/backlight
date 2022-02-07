#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
  const std::string root = "/sys/class/backlight";

  const char *envname = std::getenv("NAME");
  const char *envval = std::getenv("VAL");
  const std::string name = envname ? envname : "";
  const std::string val = envval ? envval : "";
  std::cerr << "[ENV] [NAME]: " << name << std::endl;
  std::cerr << "[ENV] [VAL]: " << val << std::endl;

  for (const auto &entry : std::filesystem::directory_iterator(root)) {
    const auto &path = entry.path();

    if (name.empty() == false && path.filename() != name) {
      continue;
    }

    unsigned long target;
    std::cerr << "[TARGET]: " << path << std::endl;

    std::ifstream(path / "max_brightness") >> target;
    std::cerr << "[MAX]: " << target << std::endl;

    if (val.empty() == false) {
      target = std::min(std::stoul(val), target);
    }

    std::ofstream(path / "brightness") << target << std::endl;
    std::cout << target << std::endl;
    return 0;
  }

  std::cerr << "FAILED" << std::endl;
  return EXIT_FAILURE;
}
