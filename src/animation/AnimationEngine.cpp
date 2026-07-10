#include "animation/AnimationEngine.h"
#include "animation/AnimationContext.h"

void AnimationEngine::begin(IAnimation* animation)
{
    current = animation;

    if (current)
        current->begin();
}

void AnimationEngine::update(LightingScene& scene)
{
    if (current)
    {
        AnimationContext context{};

        current->update(scene, context);
    }
}