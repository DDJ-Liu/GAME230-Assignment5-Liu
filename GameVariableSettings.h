#ifndef GAMEVARIABLESETTINGS_H
#define GAMEVARIABLESETTINGS_H

namespace gm {
	// Box movement speed
	const int PlayerMovementSpeedPerSecond = 600;

    const int GameWidth = 640;
    const int GameHeight = 640;

    const int PADDLE_LENGTH = 100;
    const int PADDLE_WIDTH = 20;
    const int PADDLE_BORDER_OFFSET = 40;
    const int BALL_SIZE = 300;
    const int MAX_PLAYER_NUMBER = 4;
    const float VELOCITY_AMPLIFIER = 0.05;
    const float VELOCITY_FIXED_CHANGE_AMOUNT = 80;
    const int WINNING_GOALS = 5;
    const float SCORED_PAUSE_TIME = 3;
    const float ETERNAL_PAUSE_TIME = 99999;

    enum Border {
        NoBorder = 0,
        LeftBorder = 1,
        RightBorder = 2,
        BottomBorder = 3,
        TopBorder = 4
    };
    enum MovementDirection {
        None = 0,
        Up = -1,
        Down = 1,
        Left = -2,
        Right = 2
    };
    enum AIType { simple, advanced };

}


#endif // !1
