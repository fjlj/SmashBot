#include "Multishine.h"

Multishine::Multishine(GameState *state) : Chain(state)
{
    m_controller = Controller::Instance();
}

Multishine::~Multishine()
{
}

void Multishine::PressButtons()
{
    m_startingFrame = 0;

    switch(m_state->frame % 15)
    {
        case 0:
        {
            //Down-B
			m_controller->pressButton(Controller::BUTTON_B);
            m_controller->tiltAnalog(Controller::BUTTON_MAIN, .5, 0);
            break;
        }
        case 3:
        {
            //Let go of Down-B
            m_controller->releaseButton(Controller::BUTTON_B);
            m_controller->tiltAnalog(Controller::BUTTON_MAIN, .5, .5);

            //Jump
            m_controller->pressButton(Controller::BUTTON_Y);

            break;
        }
        case 4:
        {
			//Let go of Jump
            m_controller->releaseButton(Controller::BUTTON_Y);
            break;
        }
        case 6:
        {
            //Down-B again
            m_controller->pressButton(Controller::BUTTON_B);
            m_controller->tiltAnalog(Controller::BUTTON_MAIN, .5, 0);
            break;
        }
        case 7:
        {
            //Let go of Down-B
            m_controller->releaseButton(Controller::BUTTON_B);
            m_controller->tiltAnalog(Controller::BUTTON_MAIN, .5, .5);
            break;
        }
    }
}
