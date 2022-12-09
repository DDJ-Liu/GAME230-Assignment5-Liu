#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Controller.h"
#include "Ball.h"

namespace gm {
    const float AIinterval = 0.2;

    class AIController :
        public Controller
    {
    protected:
        AIType type = AIType::simple;
        bool enabled=false;
        Ball* balls = nullptr;
        Paddle* oppostiePaddle = nullptr;
        float AItimer = 0;
    public:
        AIController(int id, Paddle& p, PaddleDirection pd, bool ai,AIType aiType);
        AIController();
        ~AIController();
        void setSensor(Ball& ballList, Paddle& paddle);
        virtual void update(sf::RenderWindow& window, float deltaTime)override;
        MovementDirection sense();
        bool isEnabled()const;
        void setEnabled(bool e);
        void setAiType(AIType t);
    };
}

#endif // !AICONTROLLER_H