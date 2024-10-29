#include "Text.h"

#include "managers/ResolutionManager.h"

using namespace game::resolutionmanager;

namespace text
{
    Text Create(std::string text, float x, float y, int font, Color color)
    {
        Text newText;

        newText.text = text;

        newText.position.x = x - (MeasureText(text.c_str(), font) / 2.f);
        newText.position.y = y + font / 2.f;

        newText.font = static_cast<int>(font * GetScalef());

        newText.color = color;

        return newText;
    }

    void Draw(Text text)
    {
        DrawText(text.text.c_str(), static_cast<int>(text.position.x), static_cast<int>(text.position.y), text.font, text.color);
    }
}


