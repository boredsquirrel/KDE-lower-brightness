#include <kwineffects.h>

class LowerBrightnessEffect : public KWin::Effect
{
public:
    LowerBrightnessEffect() {}
    ~LowerBrightnessEffect() override {}

    void prePaintScreen(KWin::ScreenPrePaintData &data, std::chrono::milliseconds presentTime) override {
        effects->prePaintScreen(data, presentTime);
    }

    void paintScreen(int mask, const QRegion &region, KWin::ScreenPaintData &data) override {
        effects->paintScreen(mask, region, data);

        // Draw the overlay
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0, 0.0, 0.0, 0.5);  // 50% black
        glRectf(-1, -1, 1, 1);
        glDisable(GL_BLEND);
    }
};

KWIN_EFFECT_FACTORY_SUPPORTED(LowerBrightnessEffect, "metadata.json", return true;)
