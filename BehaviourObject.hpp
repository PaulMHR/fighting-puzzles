#include <memory>

class BehaviourObject {
public:
    virtual void update(float deltaTime) = 0;
    virtual void handleInput(Input input) = 0;
};

typedef std::shared_ptr<BehaviourObject> BOPtr;

