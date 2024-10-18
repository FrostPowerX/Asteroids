#include "Text.h"

namespace text
{
    Text Create(std::string text, float x, float y, int font, Color color)
    {
        Text newText;

        newText.text = text;

        newText.position.x = x;
        newText.position.y = y;

        newText.font = font;

        newText.color = color;

        return newText;
    }

    void Draw(Text text)
    {
        DrawText(text.text.c_str(), static_cast<int>(text.position.x), static_cast<int>(text.position.y), text.font, text.color);
    }
}


