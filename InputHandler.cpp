#include "InputHandler.h"
InputHandler *InputHandler::s_pInstance = nullptr;
bool InputHandler::keyDown(SDL_Scancode scanCode)
{
    return mKeyBoardStates[scanCode];
}

void InputHandler::update()
{
    mKeyBoardStates = SDL_GetKeyboardState(NULL);
}
InputHandler *InputHandler::Instance()
{
    if (s_pInstance == nullptr)
    {
        s_pInstance = new InputHandler();
    }
    return s_pInstance;
}

bool InputHandler::keyUp(SDL_Scancode scanCode)
{
    return !mKeyBoardStates[scanCode];
}