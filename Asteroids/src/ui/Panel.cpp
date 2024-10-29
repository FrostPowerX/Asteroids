#include "Panel.h"

#include "managers/ResolutionManager.h"

using namespace game::resolutionmanager;

namespace panel
{
    Panel Create(Rectangle rect, string text, float minOffSetX, float maxOffSetX, float minOffSetY, float maxOffSetY, int fontSize, Color rectColor, Color textColor)
    {
        Panel newP;

        rect.width *= GetScale().x;
        rect.height *= GetScale().y;

        newP.rect = rect;
        newP.text.text = text;

        newP.minOffSetX = minOffSetX;
        newP.maxOffSetX = maxOffSetX;

        newP.minOffSetY = minOffSetY;
        newP.maxOffSetY = maxOffSetY;

        newP.text.font = static_cast<int>(fontSize * GetScalef());

        newP.rectColor = rectColor;
        newP.text.color = textColor;

        newP.rect.width = newP.minOffSetX + newP.maxOffSetX + MeasureText(newP.text.text.c_str(), newP.text.font);
        newP.rect.height = newP.minOffSetY + newP.maxOffSetY + newP.text.font;

        newP.rect.x = newP.rect.x - (newP.rect.width / 2);
        newP.rect.y = newP.rect.y - (newP.rect.height / 2);

        newP.text.position.x = newP.rect.x + newP.minOffSetX;
        newP.text.position.y = newP.rect.y + newP.minOffSetY;

        return newP;
    }

    void SetPosition(Panel& panel, Vector2 newPos)
    {
        panel.rect.x = newPos.x;
        panel.rect.y = newPos.y;

        panel.rect.x = panel.rect.x - (panel.rect.width / 2);
        panel.rect.y = panel.rect.y - (panel.rect.height / 2);

        SetText(panel, panel.text.text);
    }

    void SetText(Panel& panel, string text)
    {
        panel.text.text = text;

        panel.rect.width = panel.minOffSetX + panel.maxOffSetX + MeasureText(panel.text.text.c_str(), panel.text.font);
        panel.rect.height = panel.minOffSetY + panel.maxOffSetY + panel.text.font;

        panel.text.position.x = panel.rect.x + panel.minOffSetX;
        panel.text.position.y = panel.rect.y + panel.minOffSetY;
    }

    void SetColorText(Panel& panel, Color color)
    {
        panel.text.color = color;
    }

    void SetBackGroundColor(Panel& panel, Color color)
    {
        panel.rectColor = color;
    }

    void Draw(Panel panel)
    {
        DrawRectangleRec(panel.rect, panel.rectColor);

        text::Draw(panel.text);
    }
}

