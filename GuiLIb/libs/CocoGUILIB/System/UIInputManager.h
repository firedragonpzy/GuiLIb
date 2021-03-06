/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.sweetpome.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CocoGUI__UIInputManager__
#define __CocoGUI__UIInputManager__

#include "cocos2d.h"
#include "CocoWidget.h"

namespace cs
{
    class UIInputManager
    {
    public:
        UIInputManager();
        ~UIInputManager();
        void registWidget(CocoWidget* widget);
        void uiSceneHasChanged();
        void sortWidgets();
        void sortRootWidgets(CocoWidget* root);
        void removeManageredWidget(CocoWidget* widget);
        CocoWidget* checkEventWidget(cocos2d::CCPoint &touchPoint);
        void addCheckedDoubleClickWidget(CocoWidget* widget);
        void update(float dt);
        bool onTouchPressed(cocos2d::CCTouch* touch);
        bool onTouchMoved(cocos2d::CCTouch* touch);
        bool onTouchReleased(cocos2d::CCTouch* touch);
        bool onTouchCanceled(cocos2d::CCTouch* touch);
        bool onTouchPressed(float x,float y);
        bool onTouchMoved(float x,float y);
        bool onTouchReleased(float x,float y);
        bool onTouchCanceled(float x,float y);
    protected:
        cocos2d::CCArray* m_manageredWidget;
        CocoWidget* m_pCurSelectedWidget;
        cocos2d::CCPoint touchBeganedPoint;
        cocos2d::CCPoint touchMovedPoint;
        cocos2d::CCPoint touchEndedPoint;
        cocos2d::CCPoint touchCanceledPoint;
        bool m_bWidgetBeSorted;
        bool m_bTouchDown;
        float m_fLongClickTime;
        float m_fLongClickRecordTime;
        cocos2d::CCArray* checkedDoubleClickWidget;
    };
}

#endif /* defined(__CocoGUI__UIInputManager__) */
