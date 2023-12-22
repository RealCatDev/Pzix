#include "pzix/pzix.hpp"

namespace PZIX_NS {

  BoundingBox::BoundingBox(glm::vec3 min, glm::vec3 max)
    : m_MinBounds(min), m_MaxBounds(max) {
  }

  AABB::AABB(glm::vec3 min, glm::vec3 max)
    : BoundingBox(min, max) {
  }

  AABB::AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
    : BoundingBox(glm::vec3(minX, minY, minZ), glm::vec3(maxX, maxY, maxZ)) {
  }

  AABB::~AABB() {

  }

  bool AABB::Collides(glm::vec3 point) {
    return (point.x >= m_MinBounds.x &&
            point.x <= m_MaxBounds.x &&
            point.y >= m_MinBounds.y &&
            point.y <= m_MaxBounds.y &&
            point.z >= m_MinBounds.z &&
            point.z <= m_MaxBounds.z );
  }

  bool AABB::Collides(Ref<BoundingBox> bbox) {
    return (m_MinBounds.x < bbox->GetMaxBounds().x &&
            m_MaxBounds.x > bbox->GetMinBounds().x &&
            m_MinBounds.y < bbox->GetMaxBounds().y &&
            m_MaxBounds.y > bbox->GetMinBounds().y &&
            m_MinBounds.z < bbox->GetMaxBounds().z &&
            m_MaxBounds.z > bbox->GetMinBounds().z );
  }

}