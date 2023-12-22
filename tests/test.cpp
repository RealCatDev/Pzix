#include <pzix/pzix.hpp>

int main(int argc, char** argv) {
  std::cout << "Hello!" << std::endl;

  using namespace PZIX_NS;

  Ref<AABB> box1 = std::make_shared<AABB>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.f, 1.f, 1.f));
  Ref<AABB> box2 = std::make_shared<AABB>(glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(1.f, 1.f, 1.f));

  std::cout << "Box 1 " << (box1->Collides(box2) ? "does" : "doesn't") << " collide with box 2" << std::endl; 

  return 0;
}