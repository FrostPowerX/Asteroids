#include "Panel.h"

#include "managers/ResolutionManager.h"

using namespace game::resolutionmanager;

namespace panel
{
    Panel Create(string spriteName, Rectangle dest, string text, float minOffSetX, float maxOffSetX, float minOffSetY, float maxOffSetY, int fontSize, Color textColor)
    {
        Panel newP;

        newP.graph.sprite = GetSprite(spriteName)->texture;

        newP.graph.dest.x = dest.x * GetScale().x;
        newP.graph.dest.y = dest.y * GetScale().y;

        newP.graph.dest.width = dest.width * GetScale().x;
        newP.graph.dest.height = dest.height * GetScale().y;
        SetPosition(newP, Vector2{ dest.x, dest.y });

        newP.graph.origin = Vector2{ 0, 0 };
        newP.graph.source = Rectangle{ 0,0, static_cast<float>(newP.graph.sprite.width), static_cast<float>(newP.graph.sprite.height) };

        newP.text.text = text;

        newP.minOffSetX = minOffSetX;
        newP.maxOffSetX = maxOffSetX;

        newP.minOffSetY = minOffSetY;
        newP.maxOffSetY = maxOffSetY;

        newP.text.font = static_cast<int>(fontSize * GetScalef());

        newP.text.color = textColor;

        /*newP.graph.dest.width = newP.minOffSetX + newP.maxOffSetX + MeasureText(newP.text.text.c_str(), newP.text.font);
        newP.graph.dest.height = newP.minOffSetY + newP.maxOffSetY + newP.text.font;*/

 /*       newP.graph.dest.x = newP.graph.dest.x - (newP.graph.dest.width / 2);
        newP.graph.dest.y = newP.graph.dest.y - (newP.graph.dest.height / 2);*/

        newP.text.position.x = newP.graph.dest.x + newP.minOffSetX;
        newP.text.position.y = newP.graph.dest.y + newP.minOffSetY;

        SetText(newP, newP.text.text);

        return newP;
    }

    void SetPosition(Panel& panel, Vector2 newPos)
    {
        panel.graph.dest.x = newPos.x;
        panel.graph.dest.y = newPos.y;

        panel.graph.dest.x = panel.graph.dest.x - (panel.graph.dest.width / 2);
        panel.graph.dest.y = panel.graph.dest.y - (panel.graph.dest.height / 2);

        SetText(panel, panel.text.text);
    }

    void SetText(Panel& panel, string text)
    {
        panel.text.text = text;

        panel.text.position.x = panel.graph.dest.x + (panel.graph.dest.width / 2) - (MeasureText(panel.text.text.c_str(), panel.text.font) / 2);
        panel.text.position.y = panel.graph.dest.y + (panel.graph.dest.height / 2) - (panel.text.font / 2);
    }

    void SetColorText(Panel& panel, Color color)
    {
        panel.text.color = color;
    }

    void Draw(Panel panel)
    {
        DrawTexturePro(panel.graph.sprite, panel.graph.source, panel.graph.dest, panel.graph.origin, 0, WHITE);

        text::Draw(panel.text);
    }
}

