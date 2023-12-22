#ifndef PZIX_HPP
#define PZIX_HPP

#include "core.hpp"

namespace PZIX_NS {

  template <typename T>
  using Ref = std::shared_ptr<T>;

  class PzixBody {

  public:

    PzixBody() = default;
    virtual ~PzixBody() = default; 

  private:

  };

  class BoundingBox {
  public:
    BoundingBox(glm::vec3 min, glm::vec3 max);
    virtual ~BoundingBox() = default;

    virtual bool Collides(glm::vec3 point) = 0;
    virtual bool Collides(Ref<BoundingBox> point) = 0;

    inline glm::vec3 GetMinBounds() const { return m_MinBounds; }
    inline glm::vec3 GetMaxBounds() const { return m_MaxBounds; }

  protected:
    glm::vec3 m_MinBounds;
    glm::vec3 m_MaxBounds;
};


  class AABB : public BoundingBox {
    friend class BoundingBox;
  public:

    AABB(glm::vec3 min, glm::vec3 max);
    AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
    ~AABB();

    bool Collides(glm::vec3 point);
    bool Collides(Ref<BoundingBox> bbox);

  private:
  };

}

#endif